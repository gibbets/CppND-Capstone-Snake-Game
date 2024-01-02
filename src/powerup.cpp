#include "powerup.h"
#include "doublepoints.h"
#include "doublespeed.h"
#include <iostream>
#include <cstring>

#include <random>

PowerUpController::PowerUpController(Snake &snake, int &mul, int mulDefault, int &speed, int mulSpeedDefault) : 
    mThread(&PowerUpController::execute, this),
    mSnake(snake),
    mPowerUp(std::make_unique<DoublePoints>(SDL_Point{4, 4})),
    mMul(mul),
    mMulOld(mulDefault),
    mSpeedMul(speed),
    mSpeedMulOld(mulSpeedDefault) {

}

PowerUpController::~PowerUpController() {
    mRun = false;

    if(mThread.joinable()) {
        mThread.join();
    }
}


void PowerUpController::check() {
    std::lock_guard<std::mutex> lc(mMutex);

    int new_x = static_cast<int>(mSnake.head_x);
    int new_y = static_cast<int>(mSnake.head_y);
    if(mPowerUp) {
        if((new_x == mPowerUp->getPos().x) && (new_y == mPowerUp->getPos().y)) {
            mPowerUp->applyEffects(mMul, mSpeedMul);

            mPowerUp.reset();
        }
    }
}

void PowerUpController::execute() {
    auto begin = std::chrono::steady_clock::now();

    while(mRun) {    
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        auto duration = std::chrono::steady_clock::now() - begin;

        if(std::chrono::duration_cast<std::chrono::seconds>(duration) >= std::chrono::seconds(10)) {
            std::lock_guard<std::mutex> lc(mMutex);
            mMul = mMulOld;
            mSpeedMul = mSpeedMulOld;

            mPowerUpToggle = !mPowerUpToggle;

            if(mPowerUpToggle) {
                mPowerUp = std::make_unique<DoubleSpeed>(mSnake.generateRandomPosition());
            }
            else {
                mPowerUp = std::make_unique<DoublePoints>(mSnake.generateRandomPosition());
            }

            begin = std::chrono::steady_clock::now();
        }
    }
}

std::function<void(SDL_Renderer&, SDL_Rect)> PowerUpController::getRenderMethod() { 
    std::lock_guard<std::mutex> lc(mMutex);

    if(mPowerUp) {
        return mPowerUp->render();
    }

    return [] (SDL_Renderer&, SDL_Rect) { return; };
}
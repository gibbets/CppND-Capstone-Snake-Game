#ifndef POWERUP_H
#define POWERUP_H

#include <thread>
#include <memory>
#include <chrono>
#include <mutex>

#include "snake.h"

#include <functional>

class IPowerUp {
    public:
    // Applies the specific effects of the power up
    virtual void applyEffects(int &mul, int &speedMul) = 0;

    // Returns the current position of the power up
    virtual SDL_Point getPos() = 0;

    // Returns the method to render the power up
    virtual std::function<void(SDL_Renderer&, SDL_Rect)> render() = 0;
};

class PowerUpController {
    public:
    //Initializes the power up controller. Starts a thread to spawn and despawn every 10 s
    //a power up item at a random position
    PowerUpController(Snake &snake, int &mul, int mulDefault, int &speed, int mulSpeedDefault);

    ~PowerUpController();

    //Checks if the player hit a power up and apply the the effect to the snake
    void check();

    //Returns a function to render the current active power up
    //if no power up is active, an empty method is returned
    std::function<void(SDL_Renderer&, SDL_Rect)> getRenderMethod();

    private:
    std::thread mThread;
    std::unique_ptr<IPowerUp> mPowerUp;
    Snake &mSnake;

    std::mutex mMutex;
    
    bool mRun{true};
    int &mMul;
    int mMulOld;

    int &mSpeedMul;
    int mSpeedMulOld;

    bool mPowerUpToggle{false};

    void execute();

};

#endif
#include "doublespeed.h"

#include <iostream>

void DoubleSpeed::applyEffects(int &mul, int &speedMul){
    std::cout << "Power Up collected. Double Speed!\n";

    speedMul = 2;

}

DoubleSpeed::~DoubleSpeed() {
    std::cout << "Double Speed expired!\n";
}

SDL_Point DoubleSpeed::getPos() {
    return mPos;
}

std::function<void(SDL_Renderer&, SDL_Rect)> DoubleSpeed::render(void) {
    return [this] (SDL_Renderer& sdl_renderer, SDL_Rect block) {
        // Render food
        SDL_SetRenderDrawColor(&sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
        block.x = mPos.x * block.w;
        block.y = mPos.y * block.h;
        SDL_RenderFillRect(&sdl_renderer, &block);
    };
}
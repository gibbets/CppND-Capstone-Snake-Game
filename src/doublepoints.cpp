#include "doublepoints.h"

#include <iostream>

void DoublePoints::applyEffects(int &mul, int &speedMul) {
    std::cout << "Power Up collected. Double Points!\n";

    mul = 2;

}

DoublePoints::~DoublePoints() {
    std::cout << "Double Points expired!\n";
}

SDL_Point DoublePoints::getPos() {
    return mPos;
}

std::function<void(SDL_Renderer&, SDL_Rect)> DoublePoints::render(void) {
    return [this] (SDL_Renderer& sdl_renderer, SDL_Rect block) {
        // Render food
        SDL_SetRenderDrawColor(&sdl_renderer, 0xFF, 0x00, 0xFF, 0x00);
        block.x = mPos.x * block.w;
        block.y = mPos.y * block.h;
        SDL_RenderFillRect(&sdl_renderer, &block);
    };
}
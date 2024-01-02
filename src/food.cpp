#include "food.h"

Food::Food(SDL_Point pos) : mPos(pos) {}

SDL_Point Food::getPosition() {
    return mPos;
}
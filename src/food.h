#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"

#include "snake.h"

class Food {
    public:
    // Creates a new Food item at the specified position
     explicit Food(SDL_Point pos);

    // Returns the position of the food
     SDL_Point getPosition();

    private:
     SDL_Point mPos;
};

#endif
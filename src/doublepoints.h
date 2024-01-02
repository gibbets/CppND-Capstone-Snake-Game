#ifndef DOUBLEPOINTS_H
#define DOUBLEPOINTS_H

#include "powerup.h"

class DoublePoints : public IPowerUp {
    public:
    DoublePoints(SDL_Point pos) : mPos{pos} {};

    ~DoublePoints();

    virtual void applyEffects(int &mul, int &speedMul) override;

    virtual SDL_Point getPos() override;

    virtual std::function<void(SDL_Renderer&, SDL_Rect)> render(void) override;

    private:
    SDL_Point mPos{4, 4};

};

#endif
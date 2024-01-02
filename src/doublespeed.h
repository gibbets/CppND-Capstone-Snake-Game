#ifndef DOUBLESPEED_H
#define DOUBLESPEED_H

#include "powerup.h"

class DoubleSpeed : public IPowerUp {
    public:
    DoubleSpeed(SDL_Point pos) : mPos{pos} {};

    ~DoubleSpeed();

    virtual void applyEffects(int &mul, int &speedMul) override;

    virtual SDL_Point getPos() override;

    virtual std::function<void(SDL_Renderer&, SDL_Rect)> render(void) override;

    private:
    SDL_Point mPos{4, 4};

};

#endif
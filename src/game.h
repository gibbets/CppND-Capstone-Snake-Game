#ifndef GAME_H
#define GAME_H

#include <random>
#include <iostream>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include "powerup.h"

enum GameState : std::uint8_t {
  START,
  RUN,
  HIGHSCORE,
  SHOWHIGHSCORE,
  END
};

class Game {
 public:
  explicit Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  std::size_t mGrid_width;
  std::size_t mGrid_height;

  GameState state;
  Food mFood;

  PowerUpController pc;

  int score{0};
  int mul{1};

  int speed{1};

  void Update();
};

#endif
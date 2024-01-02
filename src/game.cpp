#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      mGrid_width(grid_width),
      mGrid_height(grid_height),
      state(GameState::START),
      mFood(snake.generateRandomPosition()),
      pc{snake, mul, 1, speed, 1} {

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    switch(state) {
      case GameState::START:
      case GameState::RUN: {
        // Input, Update, Render - the main game loop.
        if(controller.HandleInput(running, snake) == ControllerResult::ESCAPE) {
          state = GameState::SHOWHIGHSCORE;
        }
        Update();
        renderer.Render(snake, mFood.getPosition(), pc.getRenderMethod());
        pc.check();

        break;
      }
      case GameState::SHOWHIGHSCORE: {
          std::cout << "Score: " << GetScore() << "\n";
          std::cout << "Size: " << GetSize() << "\n";
          state = GameState::HIGHSCORE;

          break;
      }
      case GameState::HIGHSCORE: {
          if(controller.HandleInput(running, snake) == ControllerResult::ESCAPE) {
            state = GameState::END;
          }
        
        break;
      }
      case GameState::END:
      default: {
        running = false;
        break;
      }
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
  SDL_Point posSnake{snake.head_x, snake.head_y};
  SDL_Rect screen{0, 0, mGrid_width, mGrid_height};
  if (!snake.alive or !SDL_PointInRect(&posSnake, &screen)) {
    std::cout << "Snake died. Game Over\n";
    state = GameState::SHOWHIGHSCORE;
  }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (mFood.getPosition().x == new_x && mFood.getPosition().y == new_y) {
    score = score + mul;
    mFood = Food(snake.generateRandomPosition());
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02 * speed;
  }  
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
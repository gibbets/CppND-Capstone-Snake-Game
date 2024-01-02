#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <functional>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  explicit Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, std::function<void(SDL_Renderer&, SDL_Rect)> powerUp);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
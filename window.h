#pragma once
#include <string>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#undef main

struct Window
{
	SDL_Window* SDLWindow;
	SDL_GLContext GLContext;
};
Window CreateWindow(std::string windowName, int resX, int resY);

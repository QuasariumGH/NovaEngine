#include "Window.h"
#include <iostream>

Window CreateWindow(std::string windowName, int resX, int resY)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	Window window;
	window.SDLWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, SDL_WINDOW_OPENGL| SDL_WINDOW_RESIZABLE);
	window.GLContext = SDL_GL_CreateContext(window.SDLWindow);

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to Initialize OpenGL! gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) returned NULL " << std::endl;
		exit(1);
	}
	else
	{
		std::cout << "Initialized OpenGL! " << std::endl;
	}

	if (!window.SDLWindow)
	{
		std::cout << "Window could not be opened! Window.SDLWindow returned NULL" << std::endl;
		exit(1);
	}
	else
	{
		std::cout << "Window Opened!" << std::endl;
	}
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	return window;
}

void DestroyWindow(Window* window)
{
	SDL_GL_DeleteContext(window->GLContext);
	SDL_DestroyWindow(window->SDLWindow);
	SDL_Quit();
}



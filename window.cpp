#include "Window.h"
#include <iostream>

void CreateWindow(std::string windowName, int resX, int resY)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	Window window;
	window.SDLWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, 0);
	window.GLContext = SDL_GL_CreateContext(window.SDLWindow);

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to Initialize OpenGL" << std::endl;
		exit(1);
	}
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
}

void DestroyWindow(Window* window)
{
	SDL_GL_DeleteContext(window->GLContext);
	SDL_DestroyWindow(window->SDLWindow);
	SDL_Quit();
}

void SwapBuffers()
{
	//SDL_GL_SwapWindow();
}

#include <iostream>
#include "Window.h"

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);

	SDL_Event event;
	bool running = true;
	while (running) 
	{
		while (SDL_PollEvent(&event)) 
		{
			if (event.type == SDL_QUIT) 
			{
				running = false;
			}
			SDL_GL_SwapWindow(window.SDLWindow);
		}
	}
	std::cout << "NovaEngine Terminated";
	return 0;
}
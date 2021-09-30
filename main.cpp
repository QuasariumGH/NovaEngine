#include <iostream>
#include "Window.h"

int main()
{
	std::cout << "Hello World!\n";
	CreateWindow("Nova Engine", 1280, 720);

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
		}
	}

	return 0;
}
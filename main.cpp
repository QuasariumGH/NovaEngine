#include <iostream>
#include "Window.h"

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);
	SDL_Event event;
	bool running = true;
	while (running) // window loop
	{
		glLoadIdentity();
		glBegin(GL_QUADS);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.0f, 0.0f, 1.0f); 
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f); 
		glVertex3f(0.0f, -1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f); 
		glVertex3f(1.0f, 0.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 1.0f); 
		glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();

		SDL_GL_SwapWindow(window.SDLWindow);
		while (SDL_PollEvent(&event)) // event loop
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			if (event.type == SDL_WINDOWEVENT_RESIZED)
			{
				int w;
				int h;
				SDL_GetWindowSize(window.SDLWindow, &w, &h);
				glViewport(0, 0, w, h);
			}
		}
	}
	std::cout << "NovaEngine Terminated";
	return 0;
}
#include <iostream>
#include "window.h"
#include "shader.h"

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);
	SDL_Event event;
	bool running = true;

	float vertices[6] =
	{
		-0.5f, -0.5f, //Bottom right
		0.0f,0.5f, //Top Middle
		0.5f, -0.5f // Bottom Left
	};
	
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
	std::string vertexShader =
	"#version 330 core\n"
	"\n"
	"layout(location = 0) in vec4 position;"
	"\n"
	"void main()\n"
	"{\n"
	"gl_Position = position;\n"
	"}\n";
	std::string fragmentShader =
	"#version 330 core\n"
	"\n"
	"layout(location = 0) out vec4 color;"
	"\n"
	"void main()\n"
	"{\n"
	"color = vec4(1.0, 0.0, 0.0, 1.0);"
	"}\n";
	;
	unsigned int htShader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(htShader);
	
	while (running) // window loop
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3); //Renders triangle to sscreen
		SDL_GL_SwapWindow(window.SDLWindow);

		while (SDL_PollEvent(&event)) // event loop
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					int w;
					int h;
					SDL_GetWindowSize(window.SDLWindow, &w, &h);
					glViewport(0, 0, w, h);
				}
			}
		}
	}
	std::cout << "NovaEngine Terminated with code 0";
	return 0;
}
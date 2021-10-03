#include <iostream>
#include "window.h"
#include "shader.h"
#include "filemanagement.h"

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);

	float vertices[] =
	{
		0.0f, 1.0f, //Top Middle
		1.0f, 0.0f, 0.0f, //color
		1.0f, -1.0f, //Bottom right
		0.0f, 1.0f, 0.0f, //color
		-1.0f, -1.0f, // Bottom Left
		0.0f, 0.0f, 1.0f //color
	};
	
	//Vertex Buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 5 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 5 * sizeof(float), (char*)(2 * (sizeof(float))));
	
	std::string vertexShader = ReadFile("assets/shaders/hellotriangle.vsh");
	std::string fragmentShader = ReadFile("assets/shaders/hellotriangle.psh");
	int htShader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(htShader);
	
	bool running = true;
	// window loop
	while (running) 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3); //Renders triangle to sscreen
		SDL_GL_SwapWindow(window.SDLWindow);
		UpdateWindowEvents(window, &running);
	}
	std::cout << "Program terminated. Exited with code 0";
	return 0;
}
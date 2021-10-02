#include <iostream>
#include <fstream>
#include "window.h"
#include "shader.h"
#include <unordered_map>

std::string ReadFile(const std::string& filepath)
{
	std::string result;
	std::ifstream stream(filepath, std::ios::in, std::ios::binary);
	if (stream)
	{
		stream.seekg(0, std::ios::end);
		result.resize(stream.tellg());
		stream.seekg(0, std::ios::beg);
		stream.read(&result[0], result.size());
		stream.close();
	}
	else
	{
		std::cerr << "Error: Could not load filepath for shader. Attempted filepath: " << filepath << std::endl;
	}
	return result;
}

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);
	SDL_Event event;
	bool running = true;

	float vertices[] =
	{
		0.0f, 1.0f, //Top Middle
		1.0f, 0.0f, 0.0f, //color

		1.0f, -1.0f, //Bottom right
		0.0f, 1.0f, 0.0f, //color

		-1.0f, -1.0f, // Bottom Left
		0.0f, 0.0f, 1.0f //color
	};
	
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 5 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 5 * sizeof(float), (char*)(2 * (sizeof(float))));
	
	GLushort indices[] = { 0,1,2,0,3,4 };
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	std::string vsDirectory = "assets/shaders/vertexshader.glsl";
	std::string fsDirectory = "assets/shaders/fragmentshader.glsl";
	std::string vertexShader = ReadFile(vsDirectory);
	std::string fragmentShader = ReadFile(fsDirectory);
	int htShader = CreateShader(vertexShader, fragmentShader);
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
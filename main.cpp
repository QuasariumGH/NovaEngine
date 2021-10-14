#include <iostream>
#include "window.h"
#include "shader.h"
#include "filemanagement.h"

struct Camera{
	Vec3 offset = {0.0f,0.0f,0.0f};
};

Vec3 add(Vec3 a, Vec3 b)
{
	Vec3 sumVec;
	sumVec.x = a.x + b.x;
	sumVec.y = a.y + b.y;
	sumVec.z = a.z + b.z;
	return sumVec;
}

int main()
{
	Window window;
	window = CreateWindow("Nova Engine", 1280, 720);

	Camera viewPort;
	 viewPort.offset = {-0.5f, -1.5f, 2.0f};

	Model testMonkey;

	//Vertex Buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, testMonkey.vertices.size(), testMonkey.vertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (char*)(3 * (sizeof(float))));
	
	std::string vertexShader = ReadFile("assets/shaders/hellotriangle.vsh");
	std::string fragmentShader = ReadFile("assets/shaders/hellotriangle.psh");
	int htShader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(htShader);
	glEnable(GL_DEPTH_TEST);
	bool running = true;
	// window loop
	while (running) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, testMonkey.vertices.size()); //Renders triangle to sscreen
		SDL_GL_SwapWindow(window.SDLWindow);
		UpdateWindowEvents(window, &running);
	}
	std::cout << "Program terminated. Exited with code 0";
	Model balls = ModelFromFile("assets");
	return 0;
} 
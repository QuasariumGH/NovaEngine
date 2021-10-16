#include <iostream>
#include "window.h"
#include "shader.h"
#include "filemanagement.h"
#include "model.h"
#include "math.h"

struct Camera{
	Vec3 offset = {0.0f, 0.0f, 0.0f};
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
	Model TestMonkey;
	Window window;
	Camera viewPort;

	window = CreateWindow("Nova Engine", 1280, 720);
	viewPort.offset = {-0.5f, -1.5f, 2.0f};

	Vertex vert1;
	vert1.position = {0.0f, 0.0f, 0.0f};
	vert1.color = {1.0f, 0.0f,0.0f };

	Vertex vert2;
	vert2.position = {0.0f, 1.0f, 0.0f};
	vert1.color = {0.0f, 1.0f,0.0f };

	Vertex vert3;
	vert3.position = {1.0f, 0.0f, 0.0f};
	vert1.color = {0.0f, 0.0f, 1.0f };

	std::vector<Vertex> vertices = { vert1, vert2, vert3 };

	//Vertex Buffer
	unsigned int buffer;

	 glGenBuffers(1, &buffer);
	 glBindBuffer(GL_ARRAY_BUFFER, buffer);
	 glBufferData(GL_ARRAY_BUFFER, vertices.size(), vertices.data(), GL_STATIC_DRAW);
	 glEnableVertexAttribArray(0);
	 glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), 0);
	 glEnableVertexAttribArray(1);
	 glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (char*)(3 * (sizeof(float))));
	
	std::string vertexShader = StringFromFile("assets/shaders/hellotriangle.vsh");
	std::string fragmentShader = StringFromFile("assets/shaders/hellotriangle.psh");
	int htShader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(htShader);
	glEnable(GL_DEPTH_TEST);
	bool running = true;
	// window loop
	TestMonkey = CreateModel("assets/TestMonkey.obj");
	while (running) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size()); //Renders triangle to sscreen
		SDL_GL_SwapWindow(window.SDLWindow);
		UpdateWindowEvents(window, &running);
	}
	std::cout << "Program terminated. Exited with code 0";
	return 0;
}
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
	viewPort.offset = {0.0f, -1.5f, 2.0f};

	TestMonkey = CreateModel("assets/TestMonkey.obj");
	std::vector<Vertex> sortedVertices;
	for (int i = 0; i < TestMonkey.indexArray.size(); i++)
	{
		sortedVertices.push_back(TestMonkey.vertexArray[TestMonkey.indexArray[i]]);
	}
	//Vertex Buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sortedVertices.size() * sizeof(Vertex), sortedVertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (char*)(3 * (sizeof(float))));
	
	std::string vertexShader = StringFromFile("assets/shaders/hellotriangle.vsh");
	std::string fragmentShader = StringFromFile("assets/shaders/hellotriangle.psh");
	int htShader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(htShader);
	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < TestMonkey.vertexArray.size(); i++)
	{
		outputVec3(TestMonkey.vertexArray[i].position);
	}

	bool running = true;
	//Window Loop
	float time = 0;
	while (running) 
	{
		glUniform3f(0, viewPort.offset.x, viewPort.offset.y, viewPort.offset.z);
		viewPort.offset.y = sinf(time);
		time += 0.001;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, sortedVertices.size()); //Renders triangle to screen
		SDL_GL_SwapWindow(window.SDLWindow);
		UpdateWindowEvents(window, &running);
	}
	std::cout << "Program terminated. Exited with code 0";
	return 0;
}
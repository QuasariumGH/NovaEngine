#include <iostream>
#include "window.h"
#include "shader.h"
#include "filemanagement.h"

struct Vec3 {
	float x;
	float y;
	float z;
};

struct Vertex{
	Vec3 position = {0.0f, 0.0f, 0.0f}; 
	Vec3 color = {0.0f, 0.0f, 0.0f};
};

struct Camera{
	Vec3 offset = {-0.5, -1.5, 2};
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

	Vertex v1;
	v1.position = {0.0f, 0.0f,0.0};
	v1.position = add(v1.position,viewPort.offset);
	v1.color = {1.0f,.0f,0.0f} ;

	Vertex v2;
	v2.position = {0.5f, 1.0f,0.5f};
	v1.position = add(v2.position,viewPort.offset);
	v2.color = {0.0f, 1.0f, 0.0f};

	Vertex v3;
	v3.position = {1.0f, 0.0f, 1.};
	v1.position = add(v3.position,viewPort.offset);
	v3.color = {1.0f, 0.0f, 1.0f,};

	Vertex v4;
	v4.position = {0.0f, 0.0f, 1.0f};
	v1.position = add(v4.position,viewPort.offset);
	v4.color = {1.0f, 1.0f, 0.0f};

	Vertex v5;
	v5.position = {1.0f, 0.0f,0.0f};
	v1.position = add(v5.position,viewPort.offset);
	v5.color = {0.0f, 0.0f, 1.0f};

	Vertex vertices[] =
	{
		v1,v2,v4,
		v3,v2,v5,
		v3,v2,v4,
		v1,v2,v5,
		v1,v4,v5,
		v5,v4,v3
	};

	//Vertex Buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
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
		glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(Vertex)); //Renders triangle to sscreen
		SDL_GL_SwapWindow(window.SDLWindow);
		UpdateWindowEvents(window, &running);
	}
	std::cout << "Program terminated. Exited with code 0";
	return 0;
} 
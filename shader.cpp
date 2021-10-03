#include "shader.h"
#include <iostream>
#include <fstream>

unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	//Error logging stuff
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << type << " shader: " << message << std::endl;
	}
	return id;
}

unsigned int CreateShader(const std::string& vertextShader, const std::string& fragmentshader)
{
	unsigned int program = glCreateProgram();
	unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertextShader);
	unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentshader);

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return program;
}


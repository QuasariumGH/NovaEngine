#pragma once
#include<glad/glad.h>
#include<string>

unsigned int CompileShader(unsigned int type, const std::string& source);
unsigned int CreateShader(const std::string& vertextShader, const std::string& fragmentshader);

#pragma once
#include<glad/glad.h>
#include<string>

static int CreateShader(const std::string& vertextShader, const std::string& fragmentshader);
static unsigned int CompileShader(unsigned int type, const std::string& source)
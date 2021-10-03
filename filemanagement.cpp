#include <iostream>
#include <fstream>
#include "filemanagement.h"

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
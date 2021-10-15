#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "filemanagement.h"

std::string StringFromFile(const std::string& filepath)
{
	std::string result;
	std::ifstream ifstream(filepath, std::ios::in, std::ios::binary);
	if(!ifstream)
	{
		std::cerr << "Error: Unable to load " << filepath << std::endl;
		exit(1);
	}

	ifstream.seekg(0, std::ios::end);
	result.resize(ifstream.tellg());
	ifstream.seekg(0, std::ios::beg);
	ifstream.read(&result[0], result.size());
	ifstream.close();
	return result;
}

Model CreateModel(const std::string& filepath)
{
	std::fstream fstream(filepath);
	if (!fstream)
	{
		std::cerr << "Error: Unable to load " << filepath << std::endl;
		exit(1);
	}

	while (!fstream.eof())
	{
		std::string line;
		while (getline(fstream, line))
		{
			char lineHeader[2];
			if (line[0] != '#')
			{
				sscanf(line.c_str(), "%s", lineHeader);
			}
		}
		return Model();
	}
}

 

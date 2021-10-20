#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include "model.h"

Model CreateModel(const std::string& filepath)
{
	Model returnModel;
	std::fstream fstream(filepath);
	if (!fstream)
	{
		std::cerr << "Error: Unable to load " << filepath << std::endl;
		exit(1);
	}
	while (!fstream.eof())
	{
		std::string line;
		float x = 0, y = 0, z = 0;
		while (getline(fstream, line))
		{
			char lineHeader[64];
			if (line[0] != '#')
			{
				sscanf(line.c_str(), "%s", lineHeader);
				if (strcmp(lineHeader, "v") == 0)
				{
					sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
					Vertex vertex;
					vertex.position = { x, y, z };
					vertex.color = { rand() / float(RAND_MAX), 0.0f , rand() / float(RAND_MAX) };
					returnModel.vertexArray.push_back(vertex);
				}
				else if (strcmp(lineHeader, "f") == 0)
				{
					uint32_t _, v0, v1, v2;
					sscanf(line.c_str(), "f %u/%u/%u %u/%u/%u %u/%u/%u", &v0, &_, &_,&v1, &_, &_,&v2, &_, &_);
					returnModel.indexArray.push_back(v0 - 1);
					returnModel.indexArray.push_back(v1 - 1);
					returnModel.indexArray.push_back(v2 - 1);
				}
			}
		}
	}
	return returnModel;
}
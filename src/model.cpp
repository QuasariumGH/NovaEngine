#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include "model.h"

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
		float x = 0, y = 0, z = 0;
		while (getline(fstream, line))
		{
			char lineHeader[64];
			if (line[0] != '#')
			{
				sscanf(line.c_str(), "%s", lineHeader);
				if (strcmp(lineHeader, "v") == 0) {

					sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
					Vertex vertex; 
					vertex.position = {x, y, z};
				}
			}
		}
		return Model();
	}
}
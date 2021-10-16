
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



 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "filemanagement.h"
	
std::string StringFromFile(const std::string& filepath)
{
	std::string result;
	std::ifstream stream(filepath, std::ios::in, std::ios::binary);
	if(!stream)
	{
		std::cerr << "Error: Unable to load " << filepath << std::endl;
		exit(1);
	}

	stream.seekg(0, std::ios::end);
	result.resize(stream.tellg());
	stream.seekg(0, std::ios::beg);
	stream.read(&result[0], result.size());
	stream.close();
	return result;
}
Model CreateModel(const std::string& filepath)
{
	std::ifstream fstream(filepath, std::ios::in);
	if (!fstream)
	{
		std::cerr << "Error: Unable to load " << filepath << std::endl;
		exit(1);
		return Model();
	}

	Model returnModel;
	std::string line;
    while (std::getline(fstream, line))
    {
		//Not changing lines? Stays on first line
		if (line.substr(0) == "v" )
		{
	    }
		else if(line.substr(0) == "f")
		{
		}
		return returnModel;
   }


}

 

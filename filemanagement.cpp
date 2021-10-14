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
	Model returnModel;
	std::ifstream fstream(filepath, std::ios::in);
    std::string line;
    while (std::getline(fstream, line))
    {
		if (line.substr(0, 2) == "v " )
		{
			Vertex vertex;
	        std::istringstream sstream(line.substr(2));
	        float x, y, z;
            sstream >> x;
			sstream >> y;
			sstream >> z;
            vertex.position = {x, y, z};
			vertex.color = {0.0f, 0.0f, 0.0f};
			
	    }
		else if(line.substr(0,2) == "f ")
		{
			std::istringstream isstream;
			isstream.str(line.substr(2));
			int a,b,c; //to store mesh index
			const char* chh=line.c_str();
			sscanf (chh, "f %i/%i %i/%i %i/%i",&a,&b,&c); //here it read the line start with f and store the corresponding values in the variables
			isstream >> a;
			isstream >> b;
			isstream >> c;
			a--;
			b--;
			c--;
			faceIndex.push_back(a);
			faceIndex.push_back(b);
			faceIndex.push_back(c);
		}
		return returnModel;
   }


}

 

#pragma once
#include <vector>

struct Vec3 {
	float x;
	float y;
	float z;
};


struct Vertex {
	Vec3 position = {0.0f, 0.0f, 0.0f}; 
	Vec3 color = {0.0f, 0.0f, 0.0f};
};

struct Face {
    std::vector<Vertex> vertices[3];
};

struct Model {
    std::vector<Face> faces;
};

std::string ReadFile(const std::string& filepath);
Model ModelFromFile(std::string file);
#pragma once
#include <vector>
#include "math.h"

struct Vertex {
	Vec3 position = { 0.0f, 0.0f, 0.0f };
	Vec3 color = { 0.0f, 0.0f, 0.0f };
};

struct Face {
	std::vector<Vertex> vertices[3];
};

struct Model {
	std::vector<Face> faces;
};

Model CreateModel(const std::string& filepath);
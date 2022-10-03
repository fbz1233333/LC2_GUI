#pragma once
#include "stdafx.h"
#include "Vertex.h"

class Mesh
{
public:


public:
	// head Vertex;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

private:
	unsigned int vao, vbo, ebo;

public:
	Mesh(std::vector<Vertex> vertices);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

	void SetupArrays();
	void SetupElements();
	void DrawElements(GLenum mod);
	void DrawArrays(GLenum mod);
};


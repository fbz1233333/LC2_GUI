#pragma once
#include "stdafx.h"
#define MAX_BONES_INFLUENCE 4

class Vertex{

public:
	glm::vec3 position;
	glm::vec2 texCoords;
	glm::vec3 normals;
	int boneIds[4];
	float weights[4];
	int boneIds2[4];
	float weights2[4];
	glm::vec3 tangent;
	glm::vec3 bigTangent;

	void InitBoneData();

	Vertex();
	Vertex(float x, float y, float z);
	Vertex(glm::vec3 position);
	Vertex(glm::vec3 position, glm::vec2 texCoords);

	void addBoneData(const int& boneId, const float& weight);
	void showBoneData();
};


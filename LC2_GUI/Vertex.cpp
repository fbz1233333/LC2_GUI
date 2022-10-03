#include "Vertex.h"

void Vertex::InitBoneData()
{
	for (unsigned int i = 0; i < 4; i++) {
		boneIds[i] = -1;
		weights[i] = 0.0f;
		boneIds2[i] = -1;
		weights2[i] = 0.0f;
	}

}

Vertex::Vertex()
{
	InitBoneData();
}

Vertex::Vertex(float x, float y, float z) :
	position(glm::vec3(x, y, z)) 
{
}

Vertex::Vertex(glm::vec3 position) :position(position)
{
}

Vertex::Vertex(glm::vec3 position, glm::vec2 texCoords) : position(position), texCoords(texCoords)
{

}

void Vertex::addBoneData(const int & boneId, const float & weight)
{
	for (unsigned int i = 0; i < MAX_BONES_INFLUENCE; i++) {
		if (boneIds[i] == -1) {
			boneIds[i] = boneId;
			weights[i] = weight;
			return;
		}
	}
	for (unsigned int i = 0; i < MAX_BONES_INFLUENCE; i++) {
		if (boneIds2[i] == -1) {
			boneIds2[i] = boneId;
			weights2[i] = weight;
			return;
		}
	}
}

void Vertex::showBoneData()
{
	for (unsigned int i = 0; i < MAX_BONES_INFLUENCE; i++) {
		if (weights[i] != 0.0f) {
			LOGI("1st bone id %d, weight is %f", boneIds[i], weights[i]);
		}
	}

}

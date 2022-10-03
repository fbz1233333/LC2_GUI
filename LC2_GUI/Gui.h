#pragma once
#include "stdafx.h"

namespace Gui {

	class Shape {
	public:
		glm::ivec2 pos;
		glm::ivec2 size;
		glm::vec3 color;
		Shape();
		Shape(glm::ivec2 pos, glm::ivec2 size, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));
	};
	class Rectangle :public Shape {
	public:

		GLenum mod;
		int lineWidth = 5;

		Rectangle(glm::ivec2 pos, glm::ivec2 size,
			glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f) ,
			GLenum mod = GL_FILL, int lineWidth = 2);
	};

	class Text :public Shape {
	public:
		std::string text;
		int fontSize = 17.0f;
		Text();
		Text(glm::ivec2 pos,glm::ivec2 size, glm::vec3 color, std::string text);

	};

};
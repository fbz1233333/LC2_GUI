#pragma once
#include "stdafx.h"
#include "Gui.h"
#include "Shader.h"
#include "Mesh.h"
#include "Character.h"

using namespace Gui;

class State {
public:
	GLFWwindow* window;
	int o_width;
	int o_height;
	int width;
	int height;
	float aspect;
	float zDepth = 0.0f;
	glm::vec3 color;
	std::unique_ptr<Shader> commonShader, fontShader;
	std::unique_ptr<Mesh> squareMesh;
	std::vector<Rectangle> rects;
	std::vector<Text> texts;
	std::map<char, Character> Characters;
	unsigned int fontVao, fontVbo;
	State();

private:
	void LoadFont();
public:
	void Resize();


};
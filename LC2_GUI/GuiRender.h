#pragma once
#include "stdafx.h"
#include "Shader.h"
#include "Mesh.h"
#include "Gui.h"
#include "State.h"

using namespace Gui;

namespace {
	std::unique_ptr<State> state;
}
class GuiRender
{
public:
	static Text CreateText(const std::string& text, float fontSize);
public:
	static void OnClear();
public:

	static void Rect(glm::ivec2 pos, glm::ivec2 size);
	static void Text(const Text& text);
public:

	static void OnStart();
	static void OnInit();
	static void OnResize(int width, int height);
	static void OnRender();
	static void OnDebug();

	static void AddRect(const Rectangle& rect);
	static void AddText(const Gui::Text& text);
	static void PolyMode(int mod);

	static glm::ivec2 GetSize();
};


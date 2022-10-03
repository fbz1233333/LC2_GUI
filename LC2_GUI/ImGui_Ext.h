#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


namespace ImGui
{

	void Init(GLFWwindow* window);
	void NewGlFrame();
	void RenderData();

};


#include "ImGui_Ext.h"

void ImGui::Init(GLFWwindow * window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	io.Fonts->AddFontFromFileTTF("c:/windows/fonts/simhei.ttf", 14.0f, NULL,
		io.Fonts->GetGlyphRangesChineseFull());

	const char* glsl_version = "#version 130";
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void ImGui::RenderData()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


void ImGui::NewGlFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}



#include "GWindow.h"
#include "Shader.h"
#include "Mesh.h"
#include "GuiRender.h"
#include "GButton.h"
#include "ImGui_Ext.h"
#include "GWidget.h"

GWindow::GWindow(std::string title, int width, int height) :title(title), width(width), height(height)
{
	OnInit();
}

void GWindow::OnInit()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	// --------------------
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	GuiRender::OnInit();
}

namespace {
	GButton* button;
};


namespace Funcs {
	void* func(GWidget* widget,glm::ivec2 p) {
		
		return nullptr;
	};

	void* func2(GButton* btn, glm::ivec2 p) {

		return nullptr;
	};
}

using namespace Funcs;

void GWindow::OnStart()
{

	//button = new GButton();
	//button->SetText("hello world my name is fbz");
	//button->on_mouse_move = &func;
	//button->on_hover = &func2;

	//widgets.push_back(button);


	// Setup
}

void GWindow::OnDebug()
{
	ImGui::NewGlFrame();
	ImGui::Begin("Button");


	ImGui::End();
	GuiRender::OnDebug();
	ImGui::RenderData();

}

void GWindow::OnResize(int w, int h)
{

	GuiRender::OnResize(w, h);
}

void GWindow::OnUpdate()
{
}

void GWindow::OnRender()
{
	GuiRender::OnClear();
	GuiRender::OnRender();

}

void GWindow::OnDestroy()
{
	glfwTerminate();

}

void GWindow::OnSwap()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void GWindow::OnClose()
{
	glfwSetWindowShouldClose(window, true);
}



void GWindow::SetFrameBufferSizeCallback(GLFWframebuffersizefun callback)
{
	glfwSetFramebufferSizeCallback(window, callback);
}

void GWindow::SetCursorposCallback(GLFWcursorposfun callback)
{
	glfwSetCursorPosCallback(window, callback);
}

void GWindow::SetMouseButtonCallback(GLFWmousebuttonfun callback)
{
	glfwSetMouseButtonCallback(window, callback);

}

void GWindow::SetScrollCallback(GLFWscrollfun callback)
{
	glfwSetScrollCallback(window, callback);
}

void GWindow::SetKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(window, callback);
}

bool GWindow::ShouldClose()
{
	return glfwWindowShouldClose(window);
}


void GWindow::OnFrameChanged(int width, int height)
{
	//LOGI("n width %d n height %d", width, height);
	this->width = width;
	this->height = height;
	if (height != 0) {
		this->aspect = (float)width / float(height);
	}
	GuiRender::OnResize(width, height);
}

namespace {
	glm::ivec2 cursor_pos;
}

void GWindow::OnMouseMove(double x, double y)
{
	cursor_pos = glm::ivec2((int)x, (int)y);
	GWidget* widget = GetMouseBind(cursor_pos);
	if (widget) {
		widget->OnMouseMove(cursor_pos);
	}


}

void GWindow::OnMouseDown(int key, int mod)
{
	GWidget* widget = GetMouseBind(cursor_pos);
	if (widget) {
		widget->OnMouseDown(cursor_pos, key, mod);
	}
}

void GWindow::OnMouseUp(int key, int mod)
{
	LOGI("mouse up %d %d", key, mod);
	GWidget* widget = GetMouseBind(cursor_pos);
	if (widget) {
		widget->OnMouseUp(cursor_pos, key, mod);
	}
}

void GWindow::OnScroll(double x, double y)
{
	LOGI("scroll %lf %lf", x, y);
}

void GWindow::OnKeyDown(int key, int mod)
{
	LOGI("down key %d", key);
}

void GWindow::OnKeyRelease(int key, int mod)
{
	LOGI("release key %d", key);
}

GWidget * GWindow::GetMouseBind(glm::ivec2 pos)
{
	//return nullptr;
	//for (GWidget* widget : widgets) {
	//	if (widget->Contain(pos)) {
	//		return widget;
	//	}
	//	else {
	//		widget->OnMouseLeave(pos);
	//	}
	//}
	return nullptr;
}

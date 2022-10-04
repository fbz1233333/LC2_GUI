#include "stdafx.h"
#include "GMainWindow.h"
#include "ImGui_Ext.h"

namespace {

	GMainWindow* gWindow;

	void framebuffer_size_callback(GLFWwindow *window, int width, int height) {

		gWindow->OnFrameChanged(width, height);
	}
	void mouse_callback(GLFWwindow* window, double x, double y) {
		//LOGI("mouse_move (%lf,%lf)", x, y);
		gWindow->OnMouseMove(x, y);
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

		if (action == GLFW_PRESS) {
			gWindow->OnMouseDown(button, mods);
		}
		if (action == GLFW_RELEASE) {
			gWindow->OnMouseUp(button, mods);
		}
	}

	void scroll_callback(GLFWwindow* window, double x, double y) {
		//LOGI("scroll (%x,%y)", x, y);
		gWindow->OnScroll(x, y);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

		if (action == GLFW_PRESS) {
			gWindow->OnKeyDown(key ,mode);
		}
		else if (action == GLFW_RELEASE) {
			gWindow->OnKeyRelease(key , mode);
		}
	}

};

int main(int argc, char* argv[]) {

	gWindow = new GMainWindow("hello Main Window", 800, 600);

	gWindow->SetFrameBufferSizeCallback(framebuffer_size_callback);
	gWindow->SetCursorposCallback(mouse_callback);
	gWindow->SetScrollCallback(scroll_callback);
	gWindow->SetKeyCallback(key_callback);
	gWindow->SetMouseButtonCallback(mouse_button_callback);

	ImGui::Init(gWindow->state->window);
	while (!gWindow->ShouldClose()) {

		gWindow->OnUpdate();
		gWindow->OnRender();

		// __Debug
		gWindow->OnDebug();
		gWindow->OnSwap();
	}

	gWindow->OnDestroy();
	return 0;
}
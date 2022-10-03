#pragma once
#include "stdafx.h"
#include "GWidget.h"


class GWindow
{
public:
	GLFWwindow* window;
	std::string title = "GWindow";
	int width = 800;
	int height = 600;
	float aspect = 1.33f;

public:
	GWindow(std::string title,int width, int height);

	void OnInit();
	void OnStart();
	void OnResize(int w, int h);
	void OnUpdate();
	void OnRender();
	void OnDestroy();
	void OnSwap();
	void OnClose();

	void OnDebug();


public:
	void SetFrameBufferSizeCallback(GLFWframebuffersizefun callback);
	void SetCursorposCallback(GLFWcursorposfun callback);
	void SetMouseButtonCallback(GLFWmousebuttonfun callback);
	void SetScrollCallback(GLFWscrollfun callback);
	void SetKeyCallback(GLFWkeyfun callback);
	bool ShouldClose();

public:
	// callbacks 
	void OnFrameChanged(int width, int height);
	void OnMouseMove(double x, double y);
	void OnMouseDown(int key, int mod);
	void OnMouseUp(int key, int mod);
	void OnScroll(double x, double y);
	void OnKeyDown(int key, int mod);
	void OnKeyRelease(int key, int mod);

	GWidget* GetMouseBind(glm::ivec2 pos);
};


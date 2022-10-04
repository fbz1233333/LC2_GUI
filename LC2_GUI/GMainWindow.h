#pragma once
#include "stdafx.h"
#include "GWidget.h"
#include "State.h"

class GMainWindow :public GWidget
{
public:
	std::unique_ptr<State> state;
public:


public:
	GMainWindow(std::string title,int width, int height);

	void OnInit();
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
public:
	// DrawCalls;
	void Rect(glm::ivec2 pos, glm::ivec2 size);
	void Text(glm::ivec2 pos, std::string value);
};


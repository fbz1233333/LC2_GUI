#pragma once
#include "GWidget.h"
#include "Gui.h"

class GButton :public GWidget
{
public:
	void* (*on_hover)(GButton* wid, glm::ivec2);
	void* (*on_leave)(GButton* wid, glm::ivec2);

public:
	std::string text;

	int fontSize = 10;

public:
	void SetText(std::string text);
	GButton(glm::ivec2 pos, glm::ivec2 size);
	GButton();

	void OnSetup();
	void OnHover(glm::ivec2 p);
	void OnLeave(glm::ivec2 t);

	void OnClick(glm::ivec2 p);
	void OnMouseMove( glm::ivec2 pos);
	void OnMouseLeave(glm::ivec2 pos);

};


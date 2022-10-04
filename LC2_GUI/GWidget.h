#pragma once
#include "stdafx.h"

class GWidget
{
public:
	glm::vec3 backgroudColor = glm::vec3(1.0f, 0.0f, 1.0f);
	glm::vec3 borderColor = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 color = glm::vec3(0.0f, 1.0f, 0.0f);

public:
	void* (*on_mouse_move)(GWidget* wid,glm::ivec2);
	void* (*on_mouse_leave)(GWidget* wid, glm::ivec2);

public:
	
	GWidget* parent;
	GWidget* GetParent();
	glm::ivec2 margin = glm::ivec2(0, 0);
	glm::ivec2 padding = glm::ivec2(0, 0);
	glm::ivec2 pos;
	glm::ivec2 size;

	GWidget(GWidget* parent);
	GWidget(glm::ivec2 pos = glm::ivec2(0, 0), glm::ivec2 size = glm::ivec2(0, 0));

	virtual void OnSetup();
	virtual void OnRender();


	virtual void OnMouseMove(glm::ivec2 t);
	virtual void OnMouseLeave(glm::ivec2 t);
	virtual void OnMouseUp(glm::ivec2 t,int key, int mod);
	virtual void OnMouseDown(glm::ivec2 t, int key, int mod);

	virtual bool Contain(glm::ivec2 t);

};


#include "GButton.h"
#include "GuiRender.h"

void GButton::SetText(std::string text)
{
	this->text = text;
}

GButton::GButton(glm::ivec2 pos, glm::ivec2 size)
	:GWidget(pos, size)
{
}

GButton::GButton()
	:GWidget(glm::ivec2(0, 0), glm::ivec2(50, 10))
{
}

void GButton::OnSetup()
{
	Rectangle rect_border = Rectangle(pos, size, glm::vec3(1.0f, 0.f, 0.f), GL_LINE, 2);
	rect_border.color = borderColor;
	Rectangle rect_fill = Rectangle(pos, size, glm::vec3(1.0f, 1.f, 1.f), GL_FILL, 2);
	rect_fill.color = backgroudColor;
	Gui::Text tx = GuiRender::CreateText(this->text, fontSize);
	
	tx.color = color;
	tx.pos = this->pos;
	
	this->size = tx.size;
	rect_border.size = this->size;
	rect_fill.size = this->size;



	GuiRender::AddText(tx);
	GuiRender::AddRect(rect_border);
	GuiRender::AddRect(rect_fill);


	//State::rects.push_back(
	//	Rectangle(glm::ivec3(pos.x, pos.y, 0.1f), size, GL_FILL, 2)
	//);
}

void GButton::OnHover(glm::ivec2 p)
{
	this->backgroudColor = glm::vec3(0.0f);
	this->color = glm::vec3(1.0f);
	if (on_hover) {
		on_hover(this, p);
	}
}

void GButton::OnLeave(glm::ivec2 t)
{
	this->backgroudColor = glm::vec3(1.f);
	this->color = glm::vec3(0.f);

	if (on_leave) {
		on_leave(this, t);
	}
}

void GButton::OnClick( glm::ivec2 p)
{
}

void GButton::OnMouseMove( glm::ivec2 pos)
{
	GWidget::OnMouseMove(pos);
	OnHover(pos);
}

void GButton::OnMouseLeave(glm::ivec2 pos)
{
	GWidget::OnMouseLeave(pos);
	OnLeave(pos);
}



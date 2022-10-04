#include "GWidget.h"

GWidget * GWidget::GetParent()
{
	return parent;
}

GWidget::GWidget(GWidget * parent) :parent(parent)
{
}

GWidget::GWidget(glm::ivec2 pos,glm::ivec2 size) :pos(pos), size(size)
{
}

void GWidget::OnSetup()
{


	//GuiRender::AddRect(Gui::Rectangle(r_pos, r_size, borderColor, GL_LINE,20));
	//GuiRender::AddRect(Gui::Rectangle(r_pos, r_size, backgroudColor, GL_FILL,2));

}

void GWidget::OnRender()
{
}

void GWidget::OnMouseMove(glm::ivec2 t)
{
	if (on_mouse_move) {
		on_mouse_move(this, t);
	}
}

void GWidget::OnMouseLeave(glm::ivec2 t)
{
	if (on_mouse_leave) {
		on_mouse_leave(this, t);
	}
}

void GWidget::OnMouseUp(glm::ivec2 t, int key, int mod)
{
	//on_mouse_up(t, key, mod);
}

void GWidget::OnMouseDown(glm::ivec2 t, int key, int mod)
{
	//on_mouse_down(t, key, mod);
}

bool GWidget::Contain(glm::ivec2 t)
{

	if (
		pos.x<t.x && pos.x + size.x>t.x &&
		pos.y<t.y && pos.y + size.y>t.y
		) {

		return true;
	}

	return false;
}


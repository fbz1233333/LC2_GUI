#include "GWidget.h"
#include "GuiRender.h"

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
	glm::vec2 p_pos;
	glm::vec2 p_size;

	if (parent) {
		p_pos = parent->pos;
		p_size = parent->size;
	}
	else {
		p_pos = glm::ivec2(0, 0);
		p_size = GuiRender::GetSize();
	}
	auto r_pos = glm::ivec2(
		p_pos.x + margin.x,
		p_pos.y + margin.y
	);
	auto r_size = glm::ivec2(
		p_size.x - margin.x * 2,
		p_size.y - margin.y * 2

	);

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


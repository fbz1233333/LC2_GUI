#include "Gui.h"

using namespace Gui;

Gui::Shape::Shape()
{
}

Gui::Shape::Shape(glm::ivec2 pos, glm::ivec2 size, glm::vec3 color)
	:pos(pos), size(size), color(color)
{
}

Gui::Rectangle::Rectangle(glm::ivec2 pos, glm::ivec2 size, glm::vec3 color, GLenum mod, int lineWidth)
	: Shape(pos, size, color), mod(mod), lineWidth(lineWidth)
{
}


Gui::Text::Text()
{
}

Gui::Text::Text(glm::ivec2 pos, glm::ivec2 size, glm::vec3 color, std::string text)
	: Shape(pos, size, color), text(text)
{
}

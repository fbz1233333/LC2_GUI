#include "GMainWindow.h"
#include "ImGui_Ext.h"
#include "GWidget.h"

#define max_margin_top 36.0f
#define line_height 17.0f

GMainWindow::GMainWindow(std::string title, int width, int height) {

	state = std::make_unique<State>(title, width, height);
	OnInit();
}

void GMainWindow::OnInit()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	state->window = glfwCreateWindow(state->width, state->height, state->title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(state->window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	state->Init();
}

namespace {
	glm::ivec2 pos;
}
void GMainWindow::OnDebug()
{
	ImGui::NewGlFrame();

	ImGui::Begin("Font");

	ImGui::SliderInt("left", &pos.x, 0, state->width);
	ImGui::SliderInt("top", &pos.y, 0, state->height);
	ImGui::SliderInt("fontSize", &state->fontSize, 0, 36);
	ImGui::End();
	ImGui::RenderData();

}

void GMainWindow::OnUpdate()
{
}


void GMainWindow::OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);

	//Rect(glm::ivec2(10, 10), glm::ivec2(200, 200));

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Text(pos, "Hello World");
}

void GMainWindow::OnDestroy()
{
	glfwTerminate();

}

void GMainWindow::OnSwap()
{
	glfwSwapBuffers(state->window);
	glfwPollEvents();
}

void GMainWindow::OnClose()
{
	glfwSetWindowShouldClose(state->window, true);
}



void GMainWindow::SetFrameBufferSizeCallback(GLFWframebuffersizefun callback)
{
	glfwSetFramebufferSizeCallback(state->window, callback);
}

void GMainWindow::SetCursorposCallback(GLFWcursorposfun callback)
{
	glfwSetCursorPosCallback(state->window, callback);
}

void GMainWindow::SetMouseButtonCallback(GLFWmousebuttonfun callback)
{
	glfwSetMouseButtonCallback(state->window, callback);

}

void GMainWindow::SetScrollCallback(GLFWscrollfun callback)
{
	glfwSetScrollCallback(state->window, callback);
}

void GMainWindow::SetKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(state->window, callback);
}

bool GMainWindow::ShouldClose()
{
	return glfwWindowShouldClose(state->window);
}


void GMainWindow::OnFrameChanged(int width, int height)
{
	state->Resize();
	glViewport(0, 0, width, height);

}



void GMainWindow::OnMouseMove(double x, double y)
{



}

void GMainWindow::OnMouseDown(int key, int mod)
{

}

void GMainWindow::OnMouseUp(int key, int mod)
{

}

void GMainWindow::OnScroll(double x, double y)
{
	LOGI("scroll %lf %lf", x, y);
}

void GMainWindow::OnKeyDown(int key, int mod)
{
	LOGI("down key %d", key);
}

void GMainWindow::OnKeyRelease(int key, int mod)
{
	LOGI("release key %d", key);
}

void GMainWindow::Rect(glm::ivec2 pos, glm::ivec2 size)
{
	auto pos_axis = glm::vec2(
		2 * ((float)pos.x + (float)size.x * 0.5f) / state->width - 1.0f,
		-2 * ((float)pos.y + (float)size.y * 0.5f) / state->height + 1.0f
	);

	auto size_axis = glm::vec2(
		(float)size.x / (float)state->width, (float)size.y / (float)state->height

	);

	state->commonShader->Use();
	state->commonShader->SetVec2("size", size_axis);
	state->commonShader->SetVec2("pos", pos_axis);
	state->commonShader->SetVec3("color", state->color);
	state->commonShader->SetFloat("zDepth", state->zDepth);

	state->squareMesh->DrawArrays(GL_TRIANGLE_STRIP);

}

void GMainWindow::Text(glm::ivec2 pos, std::string text)
{
	auto color = state->color;
	auto x = (float)pos.x;
	auto y = (float)pos.y;
	auto scale = glm::vec2(((float)state->fontSize / line_height, (float)state->fontSize / line_height));

	state->fontShader->Use();
	state->fontShader->SetVec3("textColor", color);
	state->fontShader->SetVec2(
		"o_scale", glm::vec2(
		(float)state->o_width / (float)state->width,
			(float)state->o_height / (float)state->height

		)
	);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(state->fontVao);

	// 遍历文本中所有的字符
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = state->Characters[*c];
		GLfloat xpos = x + ch.Bearing.x;

		GLfloat ypos = state->height - y - (ch.Size.y - ch.Bearing.y)*scale.y - size.y - max_margin_top;

		GLfloat w = ch.Size.x * scale.x;
		GLfloat h = ch.Size.y * scale.y;
		// 对每个字符更新VBO
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// 在四边形上绘制字形纹理
		glBindTexture(GL_TEXTURE_2D, ch.TextureId);
		// 更新VBO内存的内容
		glBindBuffer(GL_ARRAY_BUFFER, state->fontVbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// 绘制四边形
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// 更新位置到下一个字形的原点，注意单位是1/64像素
		x += (ch.Advanced >> 6) * scale.x; // 位偏移6个单位来获取单位为像素的值 (2^6 = 64)
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}


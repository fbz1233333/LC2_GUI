#include "GuiRender.h"
#include "ImGui_Ext.h"

#define max_margin_top 35.0f

Text GuiRender::CreateText(const std::string& text, float fontSize)
{
	Gui::Text tx;
	tx.text = text;

	for (const char& c : text) {
		Character ch = state->Characters[c];

		//LOGI("%c %d", c, c);
		//LOGI("size w %d h%d ", ch.Size.x, ch.Size.y);
		//LOGI("bearing w %d h%d ", ch.Bearing.x, ch.Bearing.y);

		tx.size.x += ch.Size.x + ch.Bearing.x ;
		
		if (tx.size.y < ch.Size.y) {
			tx.size.y = ch.Size.y;
		}
		
		if (c == ' ') {
			tx.size.x += 25.0f;
		}

	}
	tx.size.x *= fontSize / 17.0f;
	tx.size.y *= fontSize / 17.0f;
	tx.fontSize = fontSize;
	return tx;
}

void GuiRender::OnClear()
{
	state->rects.clear();
	state->texts.clear();

}

void GuiRender::Rect(const Rectangle & rect)
{
	auto pos = rect.pos;
	auto size = rect.size;

	glLineWidth(rect.lineWidth);
	glPolygonMode(GL_FRONT_AND_BACK, rect.mod);

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
	state->commonShader->SetVec3("color", rect.color);
	state->commonShader->SetFloat("zDepth", 1.0f);

	state->squareMesh->DrawArrays(GL_TRIANGLE_STRIP);
}

void GuiRender::Text(const Gui::Text& tx)
{
	auto text = tx.text;
	auto color = tx.color;
	auto x = (float)tx.pos.x;
	auto y = (float)tx.pos.y;
	auto scale = glm::vec2(((float)tx.fontSize / 17.0f, (float)tx.fontSize/ 17.0f));

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

		GLfloat ypos = state->height-y - (ch.Size.y - ch.Bearing.y)*scale.y - tx.size.y;

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

void GuiRender::OnStart()
{
}

void GuiRender::OnInit()
{
	state = std::make_unique<State>();
	
}

void GuiRender::OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);

	//LOGI("%d size", state->rects.size());
	for (Rectangle rect : state->rects) {
		Rect(rect);
	}
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (Gui::Text tx: state->texts) {

		Text(tx);

	}
	//Text("Hello My name is fbz", left, top, scale, glm::vec3(0.0f, 0.0f, 0.0f));

}

void GuiRender::OnResize(int width, int height)
{
	LOGI("state resize");
	glViewport(0, 0, width, height);
	state->Resize();
}

void GuiRender::OnDebug()
{
	ImGui::Begin("hello");

	//ImGui::SliderInt("left", &left, 0, state->width);
	//ImGui::SliderInt("top", &top, 0, state->height);
	//ImGui::SliderFloat("scale", &scale, 0.0f, 2.0f);


	ImGui::End();

}


void GuiRender::AddRect(const Gui::Rectangle& rect)
{
	state->rects.push_back(rect);
}

void GuiRender::AddText(const Gui::Text & text)
{
	state->texts.push_back(text);
}

glm::ivec2 GuiRender::GetSize()
{

	GLFWwindow* window = glfwGetCurrentContext();
	if (window) {
		glm::ivec2 res;
		glfwGetFramebufferSize(window, &res.x, &res.y);
		return res;
	}
	else {
		return glm::ivec2(state->width, state->height);
	}
	
}

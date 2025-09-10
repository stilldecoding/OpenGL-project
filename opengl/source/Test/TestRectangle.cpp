#include "TestRectangle.h"
#include<VertexBufferLayout.h>
#include"Imgui/imgui.h"

TestRectangle::TestRectangle(std::string path) : shader(path),translationA(150,150,0)
{
	float vertices[] = {
		//position     //color
		1020.0f,180.0f, 1.0f,  0,    0,
		1020.0f,700.0f, 0,	  1.0f, 0,
		220.0f,180.0f, 0,     0,    1.0f,
		220.0f,700.0f, 0,     0,    1.0f
	};

	unsigned int index[] = { 0,1,2,0,3,2 };

	vb.Init(&vertices[0], 4 * 5 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(3);
	va.Addbuffer(vb, layout);
	ib.Init(index, sizeof(float) * 6);

}

TestRectangle::~TestRectangle()
{
}

void TestRectangle::OnRender(float DeltaTime)
{
	translate = glm::translate(glm::mat4(1.0f), translationA);
	mvp = proj * translate;
	shader.SetUniformMat4f("m_MVP", mvp);
	renderer.Draw(va, ib, shader);
}

void TestRectangle::SetColor(float r, float g, float b, float alpha)
{
	shader.SetUniform4f("u_Color", r, g, b, alpha);
}

void TestRectangle::OnImageGuiRender()
{
	ImGui::SliderFloat3("Translation A", &translationA.x, -1000, 1000);
}

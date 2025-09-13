#include "TestRectangle.h"
#include<VertexBufferLayout.h>
#include"Imgui/imgui.h"

TestRectangle::TestRectangle(std::string path) : shader(path),translationA(150,150,0),curve(0.005),amplitute(20),scale(1.0f),scaleVec(1.0f)
{
	int rows = 60, cols = 45;
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	int width = 800;
	int height = 500;

	float startX = 100.0f;
	float startY = 50.0f;

	for (int y = 0; y <= rows; y++) {
		for (int x = 0; x <= cols; x++) {
			float xpos = startX + (float)x / cols * width;
			float ypos = startY + (float)y / rows * height;
			vertices.push_back(xpos);
			vertices.push_back(ypos);
		}
	}

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			int i = y * (cols + 1) + x;
			indices.push_back(i);
			indices.push_back(i + cols + 1);
			indices.push_back(i + 1);

			indices.push_back(i + 1);
			indices.push_back(i + cols + 1);
			indices.push_back(i + cols + 2);
		}
	}

	vb.Init(&vertices[0], vertices.size() * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.Addbuffer(vb, layout);
	ib.Init(indices.data(), sizeof(unsigned int) * indices.size());

}

TestRectangle::~TestRectangle()
{
}

void TestRectangle::OnRender(float DeltaTime)
{
	translate = glm::translate(glm::mat4(1.0f), translationA);
	scale = glm::scale(glm::mat4(1.0f), scaleVec);
	model = scale * translate;
	mvp = proj * model;
	shader.SetUniform1f("time", DeltaTime);
	shader.SetUniformMat4f("m_MVP", mvp);
	shader.SetUniform1f("amplitute", amplitute);
	shader.SetUniform1f("curve", curve);
	renderer.Draw(va, ib, shader);
}

void TestRectangle::SetColor(float r, float g, float b, float alpha)
{
	shader.SetUniform4f("u_Color", r, g, b, alpha);
}

void TestRectangle::OnImageGuiRender(std::string string)
{
	ImGui::SliderFloat3(string.c_str(), &translationA.x, -1000, 1000);
	ImGui::SliderFloat("amplitute", &amplitute,10,100);
	ImGui::SliderFloat("curve", &curve,0.1,0.001);
	ImGui::SliderFloat2("Scale", &scaleVec.x,1,5);
}

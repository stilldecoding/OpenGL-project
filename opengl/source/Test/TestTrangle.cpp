#include "TestTrangle.h"
#include"Imgui/imgui.h"
#include"VertexBufferLayout.h"


TestTriangle::TestTriangle(std::string& path) : Color{ 1.0f,0.0f,0.0f,1.0f },shader(path),scaleVec(1.0f)
{

	std::vector<float> vertices{
		200,200, 1.0f,0.0f,0.0f,
		1000,200, 0.0f, 1.0f,0.0f,
		600,600 , 0.0f,0.0f,1.0f
	};
	this->vertices = vertices;
	this->path = path;


	vb.Init(&vertices[0], 5 * 3 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(3);
	va.Addbuffer(vb, layout);

}

TestTriangle::~TestTriangle()
{
}

void TestTriangle::OnRender(float DeltaTime)
{
	//model matrix
	translate = glm::translate(glm::mat4(1.0f), translationA);
	scale = glm::scale(glm::mat4(1.0f), scaleVec);
	model = translate * scale;

	//MVP matrix
	mvp = proj * model;
	shader.SetUniformMat4f("m_MVP", mvp);
	shader.SetUniform1f("time", DeltaTime);
	renderer.Draw(va,shader);

}

void TestTriangle::OnImageGuiRender(std::string string)
{
	ImGui::SliderFloat3(string.c_str(), &translationA.x, -200, 200);
	ImGui::SliderFloat2("scale", &scaleVec.x, 0, 6);
}


void TestTriangle::SetColor(float r,float g,float b,float alpha)
{
	shader.SetUniform4f("u_Color", r, g, b, alpha);
}
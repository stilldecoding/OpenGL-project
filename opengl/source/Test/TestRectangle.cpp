#include "TestRectangle.h"
#include<VertexBufferLayout.h>

TestRectangle::TestRectangle(float width,float height,std::string path) : shader(path) 
{
	float bottom_left_x = (TestRectangle::width / 2) - (width - 2);
	float bottom_left_y = (TestRectangle::height / 2) - (height - 2);
	vertices.push_back(bottom_left_x);
	vertices.push_back(bottom_left_y);
	float bottom_right_x = (TestRectangle::width / 2) + (width - 2);
	float bottom_right_y = (TestRectangle::height / 2) - (height - 2);
	vertices.push_back(bottom_right_x);
	vertices.push_back(bottom_right_y);

	float top_right_x = (TestRectangle::width / 2) + (width - 2);
	float top_right_y = (TestRectangle::height / 2) + (height - 2);

	vertices.push_back(top_right_x);
	vertices.push_back(top_right_y);
	float top_left_x = (TestRectangle::width / 2) - (width - 2);
	float top_left_y = (TestRectangle::height / 2) + (height - 2);

	vertices.push_back(top_left_x);
	vertices.push_back(top_left_y);

	unsigned int index[] = { 0,1,2,0,3,2 };

	vb.Init(vertices.data(), vertices.size() * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.Addbuffer(vb, layout);
	ib.Init(index, sizeof(float) * 6);

}

TestRectangle::~TestRectangle()
{
}

void TestRectangle::OnRender()
{
	translate = glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0, 0));
	mvp = proj * translate;
	shader.SetUniformMat4f("m_MVP", mvp);
	renderer.Draw(va, ib, shader);
}

void TestRectangle::SetColor(float r, float g, float b, float alpha)
{
	shader.SetUniform4f("u_Color", r, g, b, alpha);
}
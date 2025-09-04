#include "TestTrangle.h"

#include <VertexArray.h>
#include<Vertexbuffer.h>
#include<Shader.h>
#include<Renderer.h>
#include<VertexBufferLayout.h>


TestTriangle::TestTriangle(std::vector<float> vertices, std::string& path) : Color{ 1.0f,0.0f,0.0f,1.0f },shader(path),
	vb(vertices.data(),vertices.size() * sizeof(float))
{
	this->vertices = vertices;
	this->path = path;


	
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.Addbuffer(vb, layout);

}

TestTriangle::~TestTriangle()
{
}

void TestTriangle::OnRender()
{
	shader.SetUniformMat4f("m_MVP", proj);
	renderer.Draw(va,shader);

}

void TestTriangle::OnImageGuiRender()
{
}


void TestTriangle::SetColor(float r,float g,float b,float alpha)
{
	shader.SetUniform4f("u_Color", r, g, b, alpha);
}
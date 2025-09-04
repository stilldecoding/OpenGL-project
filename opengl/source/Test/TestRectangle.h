#pragma once
#include "Test.h"
#include<vector>
#include<string>
#include <VertexArray.h>
#include<Vertexbuffer.h>
#include<Shader.h>
#include<Renderer.h>
#include<IndexBuffer.h>
#include"glm/glm.hpp"



class TestRectangle : public test::Test
{
public:
	TestRectangle(float width,float height, std::string path);
	~TestRectangle();

	void OnRender() override;
	void SetColor(float r, float g, float b, float alpha);
	void OnImageGuiRender() override;


private:
	VertexArray va;
	VertexBuffer vb;
	IndexBuffer ib;
	Renderer renderer;
	Shader shader;

	std::vector<float> vertices;

	
	glm::mat4 translate;
	glm::mat4 mvp;

	glm::vec3 translation;
};

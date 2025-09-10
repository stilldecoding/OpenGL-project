#pragma once
#include "Test.h"
#include<vector>
#include<string>
#include <VertexArray.h>
#include<Vertexbuffer.h>
#include<Shader.h>
#include<Renderer.h>

class TestTriangle:public test::Test
{
public:
	TestTriangle(std::string& path);
	~TestTriangle();

	void OnRender(float DeltaTime) override;
	void OnImageGuiRender() override;

	void SetColor(float r, float g, float b, float alpha);

private:
	std::vector<float> vertices;
	float Color[4];
	std::string path;

	Renderer renderer;
	VertexArray va;
	VertexBuffer vb;
	Shader shader;


	glm::mat4 translate;
	glm::mat4 mvp;

	glm::vec3 translationA;
};

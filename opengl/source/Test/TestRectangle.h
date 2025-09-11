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
	TestRectangle(std::string path);
	~TestRectangle();

	void OnRender(float DeltaTime) override;
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
	glm::mat4 scale;
	glm::mat4 rotation;
	glm::mat4 model;
	glm::mat4 mvp;

	glm::vec3 translationA;
	glm::vec3 scaleVec;
	
	float curve;
	float amplitute;
	

};

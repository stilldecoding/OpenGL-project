#pragma once


#include "glm/glm.hpp"
#include"Test.h"
#include "VertexArray.h"
#include"Vertexbuffer.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include <vector>

#define M_PI 3.14159265358979323846
class TestCircle : public test::Test
{
public:
	TestCircle(float cx, float cy, float radius,std::string& path);
	~TestCircle();

	void OnRender(float delta) override;
	void OnImageGuiRender(std::string string) override;
	void SetColor(float r,float g,float b,float alpha);
	void SetTranslate(glm::vec3 translation);

private:
	std::vector<float> vertices;
	VertexArray va;
	VertexBuffer vb;
	Shader shader;
	Renderer render;

	glm::mat4 translate;
	glm::mat4 scale;
	glm::mat4 rotation;
	glm::mat4 model;
	glm::mat4 mvp;

	glm::vec3 translation;
	glm::vec3 scaleVec;
};

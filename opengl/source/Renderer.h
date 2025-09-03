#pragma once

#include<GL/glew.h>
#include<iostream>
#include"VertexArray.h"
#include"IndexBuffer.h"
#include"Shader.h"



#define ASSERT(x) if(!(x)) __debugbreak();

#define GLCALL(x) GLClearError();x;ASSERT(GLCheckError(#x,__FILE__,__LINE__))

void GLClearError();

bool GLCheckError(const char* fun_name, const char* file, int line);

class Renderer
{
public:
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawCircle(const VertexArray& va, const Shader& shader,int count);
};


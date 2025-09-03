#pragma once
#include"Renderer.h"

class VertexBuffer 
{
private:
	unsigned int gl_Renderer_ID;
public:
	VertexBuffer(const void* data,unsigned int size);
	~VertexBuffer();
	
	void Bind() const;
	void Unbind() const;

	//unsigned int Get_Vertex_ID();
};

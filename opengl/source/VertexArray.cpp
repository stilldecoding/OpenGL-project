#include "VertexArray.h"

#include"Vertexbuffer.h"
#include"VertexBufferLayout.h"


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &GL_Renderer_ID);
	this->Bind();
}

VertexArray::~VertexArray()
{
	glGenVertexArrays(1, 0);
}


void VertexArray::Addbuffer(const VertexBuffer& vb,const VertexBufferLayout& layout)
{
	this->Bind();
	const auto& elements = layout.GetElements();
	vb.Bind();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		auto element = elements[i];
		glEnableVertexAttribArray(i);
		GLCALL(glVertexAttribPointer(i, element.count, element.type, GL_FALSE, layout.GetStride(), (void *)offset));
		offset += element.count * BufferLayout::GetSizeOfType(element.type);
		
	}
	
	
}

void VertexArray::Bind() const 
{
	glBindVertexArray(GL_Renderer_ID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
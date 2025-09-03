#pragma once

class VertexBuffer;
class VertexBufferLayout;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void Addbuffer(const VertexBuffer& vb,const VertexBufferLayout& layout);


private:
	unsigned int GL_Renderer_ID;

};
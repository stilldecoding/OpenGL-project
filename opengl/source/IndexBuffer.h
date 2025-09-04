#pragma once


class IndexBuffer
{
private:
	unsigned int gl_Renderer_ID;
	unsigned int count;
public:
	IndexBuffer(const unsigned int* data,unsigned int size);
	IndexBuffer() {}
	~IndexBuffer();

	void Init(const unsigned int* data, unsigned int size);

	void Bind() const;
	void Unbind() const;

	inline unsigned int const GetCount() const { return count; }

};
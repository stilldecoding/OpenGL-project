#pragma once
#include<vector>
#include<GL/glew.h>


struct BufferLayout
{

	unsigned int count;
	unsigned int type;
	unsigned int normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:          return 4;
		case GL_UNSIGNED_INT:   return 4;
		case GL_UNSIGNED_BYTE:  return 1;
		}
		// It's good practice to assert here if the type is unknown
		// ASSERT(false); 
		return 0;
	}

};


class VertexBufferLayout
{
private:
	std::vector<BufferLayout> elements;
	unsigned int Stride;
public:
	VertexBufferLayout() : Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		elements.push_back({ count,GL_FLOAT,GL_FALSE });
		Stride += sizeof(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		elements.push_back({ count,GL_UNSIGNED_INT,GL_FALSE });
		Stride += sizeof(GL_UNSIGNED_INT) * count;
	}

	inline const std::vector<BufferLayout>& GetElements() const { return elements; }
	inline const unsigned int GetStride() const { return Stride; }

};

#include"IndexBuffer.h"
#include"Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size)
{
    glGenBuffers(1, &gl_Renderer_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_Renderer_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    count = size / sizeof(unsigned int);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &gl_Renderer_ID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_Renderer_ID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
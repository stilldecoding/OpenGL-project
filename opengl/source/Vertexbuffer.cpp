#include "Vertexbuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &gl_Renderer_ID);
    glBindBuffer(GL_ARRAY_BUFFER, gl_Renderer_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &gl_Renderer_ID);
}

void VertexBuffer::Init(const void* data, unsigned int size)
{
    glGenBuffers(1, &gl_Renderer_ID);
    glBindBuffer(GL_ARRAY_BUFFER, gl_Renderer_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_VERTEX_ARRAY, gl_Renderer_ID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_VERTEX_ARRAY, 0);
}

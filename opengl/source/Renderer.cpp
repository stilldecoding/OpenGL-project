#include "Renderer.h"

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char* fun_name, const char* file, int line)
{
    while (GLenum type = glGetError())
    {
        std::cout << "Error Code : " << type
            << "\nFile name : " << file << "\nLine number : "
            << line << "\nFunction Name: " << fun_name << "\n";
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
    va.Bind();
    ib.Bind();
    shader.UseProgram();
    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::Draw(const VertexArray& va, const Shader& shader)
{
    va.Bind();
    shader.UseProgram();
    glDrawArrays(GL_TRIANGLES,0,3);
}

void Renderer::DrawCircle(const VertexArray& va, const Shader& shader, int count)
{
    va.Bind();
    shader.UseProgram();
    glDrawArrays(GL_TRIANGLE_FAN, 0, count);
}



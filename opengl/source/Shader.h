#pragma once
#include<GL/glew.h>

#include <fstream>
#include<string>
#include<sstream>
#include <unordered_map>
#include "glm/glm.hpp"

struct ShaderSource {
    std::string VertexShader;
    std::string FragmentShader;
};


class Shader
{
private:
    ShaderSource src;
    unsigned int Gl_Renderer_ID;
    unsigned int vertex_shader;
    unsigned int fragment_shader;

    std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(std::string& filepath);
	~Shader();

    void UseProgram() const;
    void UnuseProgram() const;


    int GetUniformLocation(const std::string& name);
    void SetUniform1i(const char* name, int x);
    void SetUniform4f(const char* name,float x1, float x2, float x3, float x4);
    void SetUniformVec4f(const char* name, glm::vec4 vec4);
    void SetUniform1f(const char* name, float x1);
    void SetUniformMat4f(const char* name,const glm::mat4& mvp);
private:
    ShaderSource ParseShader(const std::string& filepath);
    static unsigned int CompileShader(std::string& source, unsigned int type);
    static unsigned int CreateShader(std::string& vertexshader, std::string& fragmentshader);

    
};

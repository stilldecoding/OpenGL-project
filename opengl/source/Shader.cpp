#include "Shader.h"
#include<iostream>
#include"Renderer.h"

Shader::Shader(std::string& filepath)
{
    src = ParseShader(filepath);
    Gl_Renderer_ID = CreateShader(src.VertexShader, src.FragmentShader);
    GLCALL(glLinkProgram(Gl_Renderer_ID));
    GLCALL(glValidateProgram(Gl_Renderer_ID));
    this->UseProgram();
}

Shader::~Shader()
{
    glDeleteProgram(Gl_Renderer_ID);
}

void Shader::UseProgram() const
{
    glUseProgram(Gl_Renderer_ID);
}

void Shader::UnuseProgram()const 
{
    glUseProgram(0);
}

ShaderSource Shader::ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {

        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return  { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(std::string& source, unsigned int type)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* mess = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, mess);
        std::cout << mess << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    int location_buffer = glGetUniformLocation(Gl_Renderer_ID, name.c_str());
    if (location_buffer == -1) 
    {
        std::cout << "Uniform Not found....Check Name\n";
    }

    m_UniformLocationCache[name] = location_buffer;
    return location_buffer;
}

void Shader::SetUniform1i(const char* name, int x)
{
    GLCALL(glUniform1i(GetUniformLocation(name), x));
}

unsigned int Shader::CreateShader(std::string& vertexshader, std::string& fragmentshader)
{
    GLCALL(unsigned int program = glCreateProgram());
    GLCALL(unsigned int vertex_shader = Shader::CompileShader(vertexshader, GL_VERTEX_SHADER));
    GLCALL(unsigned int fragment_shader = Shader::CompileShader(fragmentshader, GL_FRAGMENT_SHADER));

    GLCALL(glAttachShader(program, vertex_shader));
    GLCALL(glAttachShader(program, fragment_shader));

    return program;
}


void Shader::SetUniform4f(const char* name,float x1, float x2, float x3, float x4)
{
    
    GLCALL(glUniform4f(GetUniformLocation(name), x1, x2, x3, x4));
}

void Shader::SetUniformVec4f(const char* name, glm::vec4 vec4)
{
    SetUniform4f(name, vec4.x, vec4.y, vec4.z, vec4.w);
}

void Shader::SetUniform1f(const char* name, float x1)
{
    GLCALL(glUniform1f(GetUniformLocation(name),x1));
}

void Shader::SetUniformMat4f(const char* name,const glm::mat4& matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

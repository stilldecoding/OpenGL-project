
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include<cmath>
#include"Vertexbuffer.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"VertexBufferLayout.h"
#include"Shader.h"
#include"Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include"Vendor/Imgui/imgui.h"
#include"Vendor/Imgui/imgui_impl_glfw.h"
#include"Vendor/Imgui/imgui_impl_opengl3.h"
#include "Test/TestClearColor.h"
#include "Test/TestTrangle.h"
#include "Test/TestRectangle.h"

#define M_PI 3.14159265358979323846

std::vector<float> generateCircleVertices(float cx, float cy, float radius, int numSegments);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "OPENGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

/* Make the window's context current */
glfwMakeContextCurrent(window);

if (glewInit() != GLEW_OK)
std::cout << "ERROR" << '\n';

std::cout << glGetString(GL_VERSION) << std::endl;


glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 360.0f, -1.0f, 1.0f);
glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
//glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 0, 0));

glm::mat4 mvp = proj * view;


float position[] = {
    // position     // texcoord
   200.0f, 200.0f,   0.0f, 0.0f,  // bottom-left
    300.0f, 200.0f,   1.0f, 0.0f,  // bottom-right
    300.0f,  300.0f,   1.0f, 1.0f,  // top-right
   200.0f,  300.0f,   0.0f, 1.0f   // top-left
};


unsigned int index[] = {
       0,1,2,
       0,2,3
};


//vertex buffer creation and binding
VertexBuffer vb(position, 4 * 4 * sizeof(float));

//Index buffer object creation and binding
IndexBuffer ib(index, 6 * sizeof(unsigned int));

VertexBufferLayout layout;
layout.Push<float>(2);
layout.Push<float>(2);
VertexArray vao;
vao.Addbuffer(vb, layout);

std::string path = "resource/shader/basic.shader";


GLCALL(Shader shader(path));



GLCALL(shader.SetUniform4f("u_Color", 0.9f, 0.0f, 0.0f, 1.0f));
GLCALL(shader.SetUniformMat4f("m_MVP", mvp));


//Texture texture("resource/Texture/texture.png");
Renderer renderer;
//texture.Bind(0);
//GLCALL(shader.SetUniform1i("u_Texture", 0));


/*VertexArray va1;

std::vector<float> vertices = generateCircleVertices(320.0f, 160.0f, 50.0f, 50);

VertexBuffer va_circle(vertices.data(), vertices.size() * sizeof(float));
VertexBufferLayout circle_layout;
circle_layout.Push<float>(2);
va1.Addbuffer(va_circle,circle_layout);*/

shader.SetUniformMat4f("m_MVP", mvp);

float speed = 1.5f;
float curr_x = 200;



IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGui_ImplGlfw_InitForOpenGL(window, true);
ImGui::StyleColorsDark();
ImGui_ImplOpenGL3_Init((char*)glGetString(330));

ImGuiIO& io = ImGui::GetIO(); (void)io;
io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;


// Setup Dear ImGui style
ImGui::StyleColorsDark();
//ImGui::StyleColorsLight();



bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

test::ClearColor clearColor;

TestTriangle triangle({ 100,100,150,200,200,100 }, path);
TestRectangle rec(100.0f, 100.0f, path);

/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
    clearColor.OnRender();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    

    //clearColor.OnImageGuiRender();
    //GLCALL(renderer.Draw(vao, ib, shader));
    
    {
        triangle.SetColor(1, 0, 0, 1);
        triangle.OnRender();
    }

    {
        rec.SetColor(1, 0, 0, 1);
        rec.OnImageGuiRender();
        rec.OnRender();

    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    glfwSwapBuffers(window);

    
    glfwPollEvents();
}

    //glDeleteProgram(shader);
ImGui_ImplOpenGL3_Shutdown();
ImGui_ImplGlfw_Shutdown();
ImGui::DestroyContext();
glfwTerminate();
return 0;
}

std::vector<float> generateCircleVertices(float cx, float cy, float radius, int numSegments) {
    std::vector<float> vertices;

    // Center vertex for triangle fan
    vertices.push_back(cx);
    vertices.push_back(cy);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = cx + radius * cosf(angle);
        float y = cy + radius * sinf(angle);
        vertices.push_back(x);
        vertices.push_back(y);
    }

    return vertices;
}

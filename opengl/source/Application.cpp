
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
    window = glfwCreateWindow(1600, 900, "OPENGL", NULL, NULL);
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


glm::mat4 proj = glm::ortho(0.0f, 1690.0f, 0.0f, 900.0f, -1.0f, 1.0f);
glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
//glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 0, 0));

glm::mat4 mvp = proj * view;






std::string path = "resource/shader/basic.shader";


GLCALL(Shader shader(path));





//Texture texture("resource/Texture/texture.png");
Renderer renderer;
//texture.Bind(0);
//GLCALL(shader.SetUniform1i("u_Texture", 0));



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

bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

test::ClearColor clearColor;

TestTriangle triangle( path);
TestRectangle rec(path);
rec.SetColor(1, 0, 0, 1);
/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
    clearColor.OnRender(0);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    

    clearColor.OnImageGuiRender();
    
    

    //triangle.OnRender(0);
    //triangle.OnImageGuiRender();
    rec.OnRender(0);

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

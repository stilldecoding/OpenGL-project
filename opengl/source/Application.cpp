
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include<cmath>
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
#include "Test/TestCircle.h"




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


std::string path = "resource/shader/basic.shader";
std::string path_circle = "resource/shader/circle.shader";



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

//TestTriangle triangle( path);
//TestRectangle rec(path);
//rec.SetColor(1, 0, 0, 1);

TestCircle sun(800.0f, 450.0f, 40.0f, path);
sun.SetColor(0, 0.5, 0.1, 1);

TestCircle earth(800, 450, 100, path_circle);
earth.SetColor(1, 1, 0, 1);



float r = 80.0f;


/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
    clearColor.OnRender(0);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    clearColor.OnImageGuiRender("");
    
    float time = glfwGetTime();

    sun.OnRender(time);

    float angle = time;
    float x = r * cos(angle);
    float y = r * sin(angle);

    glm::mat4 t = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 1));

    //earth.SetTranslate(glm::vec3(x,y,1.0f));
    earth.OnRender(time);
    earth.OnImageGuiRender("earth Translate");
    sun.OnImageGuiRender("Sun Translate");

    

    ImGui::SliderFloat("radius", &r, 7, 1000);

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

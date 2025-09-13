#include "TestClearColor.h"
#include"Imgui/imgui.h"
#include "Renderer.h"


test::ClearColor::ClearColor() : clear_color{0.0f,0.0f,0.0f,1.0f}
{
}

test::ClearColor::~ClearColor()
{
}

void test::ClearColor::OnRender(float DeltaTime)
{

    glClearColor(clear_color[0],clear_color[1],clear_color[2],clear_color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

void test::ClearColor::OnUpdate()
{
}

void test::ClearColor::OnImageGuiRender(std::string string)
{
	ImGui::ColorEdit4("Clear Color", clear_color);
}

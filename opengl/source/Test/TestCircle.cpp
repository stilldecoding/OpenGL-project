#include "TestCircle.h"

TestCircle::TestCircle(float cx, float cy, float radius,std::string& path) : shader(path),scaleVec(1.0f),translation(1.0f),scale(1.0f)
{
    int numSegments = 50;
    vertices.clear();

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

    vb.Init(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.Addbuffer(vb, layout);


}

TestCircle::~TestCircle()
{
}

void TestCircle::OnRender(float delta)
{
    

    translate = glm::translate(glm::mat4(1.0f), translation);
    scale = glm::scale(glm::mat4(1.0f), scaleVec);

    model = translate * scale;
    mvp = proj * model;
    shader.SetUniformMat4f("m_MVP", mvp);

    render.DrawCircle(va, shader,vertices.size()/2);
}

void TestCircle::OnImageGuiRender(std::string string)
{
    ImGui::SliderFloat3(string.c_str(), &translation.x, -1000, 1000);
}

void TestCircle::SetColor(float r, float g, float b,float alpha) {
    shader.SetUniform4f("u_Color", r, g, b, alpha);
}

void TestCircle::SetTranslate(glm::vec3 translation)
{
    this->translation = translation;
}



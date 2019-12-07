#include "BackgroundLayer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

const std::string &Hazel::BackgroundLayer::GetName() const
{
    static const std::string name = "Background";
    return name;
}

void Hazel::BackgroundLayer::OnAttach()
{
}

void Hazel::BackgroundLayer::OnDetach()
{
}

void Hazel::BackgroundLayer::OnUpdate()
{
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Hazel::BackgroundLayer::OnImGuiRender()
{
}
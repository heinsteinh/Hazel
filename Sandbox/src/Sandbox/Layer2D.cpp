#include "Layer2D.h"

//TEMPORARY
#include "../../Hazel/src/Platform/OpenGL/OpenGLShader.h"

namespace Sandbox
{
    Layer2D::Layer2D(Hazel::Window &parent)
        : parent(parent),
        renderer(parent),
        cameraController(parent)
    {
    }

    void Layer2D::OnAttach()
    {
        Hazel::ObjectFactory &factory = parent.GetContext().GetFactory();
        squareVertexArray = factory.CreateVertexArray();

        auto vertexBuffer = factory.CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f});

        vertexBuffer->SetLayout({{Hazel::ShaderDataType::Float3, "a_Position"}});
        squareVertexArray->AddVertexBuffer(vertexBuffer);
        auto indexBuffer = factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0});
        squareVertexArray->SetIndexBuffer(indexBuffer);

        flatColorShader = factory.CreateShader("FlatColor", "assets\\shaders\\FlatColor.glsl");
    }

    void Layer2D::OnDetach()
    {
    }

    void Layer2D::OnUpdate(Hazel::Timestep deltaTime)
    {
        framerate = 1.0f / deltaTime.ToSeconds();
        parent.GetContext().GetDrawer().Clear();
        cameraController.OnUpdate(deltaTime);

        renderer.BeginScene(cameraController.GetCamera());

        auto openGLShader = std::dynamic_pointer_cast<Hazel::OpenGLShader>(flatColorShader);
        openGLShader->Bind();
        openGLShader->UploadUniformFloat4("u_Color", color);
        renderer.Submit(flatColorShader, squareVertexArray, glm::mat4(1.0f));

        renderer.EndScene();
    }

    void Layer2D::OnImGuiRender()
    {
        if (showFps)
        {
            ImGui::Begin("Framerate", &showFps);
            ImGui::Text("%.2f FPS", framerate);
            ImGui::End();
        }
        if (showColorPicker)
        {
            ImGui::Begin("Settings", &showColorPicker);
            ImGui::ColorPicker4("Color", glm::value_ptr(color));
            ImGui::End();
        }
    }

    void Layer2D::OnEvent(Hazel::Event &e)
    {
        e.Dispatch(&cameraController);
    }

    void Layer2D::OnKeyPressed(Hazel::KeyPressedEvent &e)
    {
        if (e.GetKey() == Hazel::Key::R)
        {
            cameraController.SetRotationEnabled(!cameraController.HasRotationEnabled());
        }
        if (e.GetKey() == Hazel::Key::I)
        {
            showFps = showColorPicker = true;
        }
    }
}
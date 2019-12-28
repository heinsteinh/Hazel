#include "Hazel.h"

#include <cmath>

static const std::string vertexSource = R"(
    #version 330 core

    layout(location = 0) in vec3 a_Position;
    layout(location = 1) in vec4 a_Color;

    uniform mat4 u_ViewProjection;

    out vec3 v_Position;
    out vec4 v_Color;

    void main()
    {
        v_Position = a_Position;
        v_Color = a_Color;
        gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
    }

)";

static const std::string fragmentSource = R"(
    #version 330 core

    layout(location = 0) out vec4 color;

    in vec3 v_Position;
    in vec4 v_Color;

    void main()
    {
        color = vec4(v_Position * 0.5 + 0.5, 1.0);
        color = v_Color;
    }

)";

class TriangleLayer : public Hazel::Layer
{
private:
    std::string name = "TriangleLayer";
    const Hazel::Window &parent;
    Hazel::Renderer renderer;
    std::shared_ptr<Hazel::Shader> shader;
    std::shared_ptr<Hazel::VertexArray> triangleVertexArray;
    Hazel::OrthographicCamera camera = {{-1.6f, 1.6f, -0.9f, 0.9f}};
    glm::vec3 cameraPosition{0.0f};
    float cameraRotation = 0.0f;
    float cameraSpeed = 0.1f;

public:
    TriangleLayer(const Hazel::Window &parent)
        : parent(parent),
        renderer(parent)
    {
    }

    virtual void OnUpdate() override
    {
        auto &input = parent.GetInput();
        if (input.IsKeyPressed(Hazel::Key::Up))
        {
            cameraPosition.y += cameraSpeed;
        }
        if (input.IsKeyPressed(Hazel::Key::Down))
        {
            cameraPosition.y -= cameraSpeed;
        }
        if (input.IsKeyPressed(Hazel::Key::Right))
        {
            cameraPosition.x += cameraSpeed;
        }
        if (input.IsKeyPressed(Hazel::Key::Left))
        {
            cameraPosition.x -= cameraSpeed;
        }

        for (int i = 0; i < 3; i++)
        {
            if (cameraPosition[i] > 1.0f)
            {
                cameraPosition[i] = 1.0f;
            }
            else if (cameraPosition[i] < -1.0f)
            {
                cameraPosition[i] = -1.0f;
            }
        }

        if (input.IsButtonPressed(Hazel::MouseButton::B1))
        {
            cameraRotation += 10 * cameraSpeed;
        }
        if (input.IsButtonPressed(Hazel::MouseButton::B2))
        {
            cameraRotation -= 10 * cameraSpeed;
        }
        cameraRotation = std::remainderf(cameraRotation, 360.0f);

        camera.SetPosition(cameraPosition);
        camera.SetRotation(cameraRotation);
        renderer.BeginScene(camera);
        renderer.Submit(shader, triangleVertexArray);
        renderer.EndScene();
    }

    virtual void OnAttach() override
    {
        const Hazel::Context &context = parent.GetContext();
        triangleVertexArray.reset(context.CreateVertexArray());

        std::shared_ptr<Hazel::VertexBuffer> vertexBuffer(context.CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
             0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f}));

        vertexBuffer->SetLayout({
            {Hazel::ShaderDataType::Float3, "a_Position"},
            {Hazel::ShaderDataType::Float4, "a_Color"}});

        triangleVertexArray->AddVertexBuffer(vertexBuffer);

        std::shared_ptr<Hazel::IndexBuffer> indexBuffer(context.CreateIndexBuffer({0, 1, 2}));
        triangleVertexArray->SetIndexBuffer(indexBuffer);

        shader.reset(context.CreateShader(vertexSource, fragmentSource));
    }

    virtual void OnDetach() override
    {
    }

    virtual const std::string &GetName() const override
    {
        return name;
    }

    virtual void OnImGuiRender() override
    {
    }

    virtual void OnMouseScrolled(Hazel::MouseScrolledEvent &e) override
    {
        camera.SetRotation(std::remainderf(camera.GetRotation() + (float)e.GetYOffset(), 360.0f));
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        Hazel::Info("Sandbox creation");
        PushLayer(new TriangleLayer(GetWindow()));
    };

    virtual void OnKeyPressed(Hazel::KeyPressedEvent &e) override
    {
        if (e.GetKey() == Hazel::Key::I)
        {
            ShowImGui(true);
        }
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    return new Sandbox();
}
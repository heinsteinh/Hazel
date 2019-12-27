#include "Hazel.h"

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
    Hazel::OrthographicCamera camera = {{-2.0f, 2.0f, -2.0f, 2.0f}};

public:
    TriangleLayer(const Hazel::Window &parent)
        : parent(parent),
        renderer(parent)
    {
    }

    virtual void OnUpdate() override
    {
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

    virtual void OnKeyPressed(Hazel::KeyPressedEvent &e) override
    {
        glm::vec3 position = camera.GetPosition();
        switch (e.GetKey())
        {
        case Hazel::Key::Up:
            position += glm::vec3(0.0f, 0.1f, 0.0f);
            break;
        case Hazel::Key::Down:
            position += glm::vec3(0.0f, -0.1f, 0.0f);
            break;
        case Hazel::Key::Right:
            position += glm::vec3(0.1f, 0.0f, 0.0f);
            break;
        case Hazel::Key::Left:
            position += glm::vec3(-0.1f, 0.0f, 0.0f);
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            if (position[i] > 1.0f)
            {
                position[i] = 1.0f;
            }
            else if (position[i] < -1.0f)
            {
                position[i] = -1.0f;
            }
        }
        camera.SetPosition(position);
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
#include "Hazel.h"

#include <cmath>

static const std::string vertexSource = R"(
    #version 330 core

    layout(location = 0) in vec3 a_Position;
    layout(location = 1) in vec4 a_Color;

    uniform mat4 u_ViewProjection;
    uniform mat4 u_Transform;

    out vec3 v_Position;
    out vec4 v_Color;

    void main()
    {
        v_Position = a_Position;
        v_Color = a_Color;
        gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
    }

)";

static const std::string fragmentSource = R"(
    #version 330 core

    layout(location = 0) out vec4 color;

    in vec3 v_Position;
    in vec4 v_Color;

    void main()
    {
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
    glm::vec3 trianglePosition{0.0f};
    float cameraRotation = 0.0f;
    float cameraTranslationSpeed = 1.0f;
    float cameraRotationSpeed = 10.0f;
    double framerate = 0.0;

public:
    TriangleLayer(const Hazel::Window &parent)
        : parent(parent),
        renderer(parent)
    {
    }

    virtual void OnUpdate(Hazel::Timestep deltaTime) override
    {
        framerate = 1.0 / deltaTime;
        auto &input = parent.GetInput();

        // Test moving camera
        if (input.IsKeyPressed(Hazel::Key::Up))
        {
            cameraPosition.y += cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Down))
        {
            cameraPosition.y -= cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Right))
        {
            cameraPosition.x += cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Left))
        {
            cameraPosition.x -= cameraTranslationSpeed * deltaTime;
        }

        // Test rotate camera
        if (input.IsButtonPressed(Hazel::MouseButton::B1))
        {
            cameraRotation += 10 * cameraRotationSpeed * deltaTime;
        }
        if (input.IsButtonPressed(Hazel::MouseButton::B2))
        {
            cameraRotation -= 10 * cameraRotationSpeed * deltaTime;
        }
        cameraRotation = std::remainderf(cameraRotation, 360.0f);

        // Test moving triangle
        if (input.IsKeyPressed(Hazel::Key::D))
        {
            trianglePosition.x += cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::A))
        {
            trianglePosition.x -= cameraTranslationSpeed * deltaTime;
        }

        // Set camera position
        camera.SetPosition(cameraPosition);
        camera.SetRotation(cameraRotation);

        // Render
        renderer.BeginScene(camera);

        // Test multiple triangles
        static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
        for (int y = 0; y < 20; y++)
        {
            for (int x = 0; x < 20; x++)
            {
                glm::mat4 transform = glm::translate(
                    glm::mat4(1.0f),
                    {0.11f * x + trianglePosition.x, 0.11f * y, 0.0f})
                    * scale;
                renderer.Submit(shader, triangleVertexArray, transform);
            }
        }

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
        ImGui::Begin("Framerate");
        ImGui::Text("%f FPS", framerate);
        ImGui::End();
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
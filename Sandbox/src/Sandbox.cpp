#include "Hazel.h"

//TEMPORARY
#include "../../Hazel/src/Platform/OpenGL/OpenGLShader.h"

static const std::string vertexSource = R"(
    #version 330 core

    layout(location = 0) in vec3 a_Position;

    uniform mat4 u_ViewProjection;
    uniform mat4 u_Transform;

    void main()
    {
        gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
    }

)";

static const std::string fragmentSource = R"(
    #version 330 core

    layout(location = 0) out vec4 color;

    uniform vec4 u_Color;

    void main()
    {
        color = u_Color;
    }

)";

class TestLayer : public Hazel::Layer
{
private:
    Hazel::Window &parent;
    Hazel::Renderer renderer;

    Hazel::OrthographicCameraController cameraController;

    Hazel::ShaderLibrary library;
    Hazel::SharedPtr<Hazel::Shader> uniformShader;

    Hazel::SharedPtr<Hazel::VertexArray> squareVertexArray;

    Hazel::SharedPtr<Hazel::Texture2D> texture;
    Hazel::SharedPtr<Hazel::Texture2D> overlay;

    glm::vec3 gridPosition{0.0f};
    glm::vec4 gridColor = {0.2f, 0.3f, 0.8f, 1.0f};

    double framerate = 0.0;

public:
    TestLayer(Hazel::Window &parent)
        : parent(parent),
        renderer(parent),
        cameraController(parent),
        library(parent.GetContext().GetFactory())
    {
    }

    virtual void OnEvent(Hazel::Event &e) override
    {
        e.Dispatch(&cameraController);
    }

    virtual void OnKeyPressed(Hazel::KeyPressedEvent &e) override
    {
        if (e.GetKey() == Hazel::Key::R)
        {
            cameraController.SetRotationEnabled(!cameraController.HasRotationEnabled());
        }
    }

    virtual void OnUpdate(Hazel::Timestep deltaTime) override
    {
        static double alpha = 0.05;
        static double previous = 0.0;
        double value = 1.0 / deltaTime;
        framerate = alpha * value + (1.0 - alpha) * previous;
        previous = framerate;

        cameraController.OnUpdate(deltaTime);

        // Test moving grid
        static const float translationSpeed = 1.0f;
        auto &input = parent.GetInput();
        if (input.IsKeyPressed(Hazel::Key::Right))
        {
            gridPosition.x += translationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Left))
        {
            gridPosition.x -= translationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Up))
        {
            gridPosition.y += translationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::Down))
        {
            gridPosition.y -= translationSpeed * deltaTime;
        }

        // Clear color
        parent.GetContext().GetDrawer().Clear();

        // Render
        renderer.BeginScene(cameraController.GetCamera());

        auto openGLShader = std::dynamic_pointer_cast<Hazel::OpenGLShader>(uniformShader);

        static const std::string uniformName = "u_Color";
        openGLShader->Bind();
        openGLShader->UploadUniformFloat4(uniformName, gridColor);

        // Test multiple squares
        static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                glm::mat4 transform = glm::translate(
                    glm::mat4(1.0f),
                    {0.11f * x + gridPosition.x, 0.11f * y + gridPosition.y, 0.0f}
                ) * scale;
                renderer.Submit(uniformShader, squareVertexArray, transform);
            }
        }
        static const std::string textureName = "Texture";
        auto textureShader = library.Get(textureName);
        texture->Bind();
        renderer.Submit(textureShader, squareVertexArray, glm::mat4(1.0f));
        overlay->Bind();
        renderer.Submit(textureShader, squareVertexArray, glm::mat4(1.0f));

        renderer.EndScene();
    }

    virtual void OnAttach() override
    {
        static const glm::vec4 clearColor = {0.45f, 0.55f, 0.60f, 1.00f};
        parent.GetContext().GetDrawer().SetClearColor(clearColor);

        cameraController.SetRotationEnabled(true);

        Hazel::ObjectFactory &factory = parent.GetContext().GetFactory();

        squareVertexArray = factory.CreateVertexArray();

        auto vertexBuffer = factory.CreateVertexBuffer({
            -0.8f, -0.45f, 0.0f, 0.0f, 0.0f,
             0.8f, -0.45f, 0.0f, 1.0f, 0.0f,
             0.8f,  0.45f, 0.0f, 1.0f, 1.0f,
            -0.8f,  0.45f, 0.0f, 0.0f, 1.0f});

        vertexBuffer->SetLayout({
            {Hazel::ShaderDataType::Float3, "a_Position"},
            {Hazel::ShaderDataType::Float2, "a_TexCoord"}});

        squareVertexArray->AddVertexBuffer(vertexBuffer);

        auto indexBuffer = factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0});
        squareVertexArray->SetIndexBuffer(indexBuffer);

        uniformShader = factory.CreateShader("Uniform", vertexSource, fragmentSource);
        auto textureShader = library.Load("assets\\shaders\\Texture.glsl");
        texture = factory.CreateTexture2D("assets\\textures\\Test.jpg");
        overlay = factory.CreateTexture2D("assets\\textures\\TestOverlay.png");

        // TEST
        auto openGLShader = std::dynamic_pointer_cast<Hazel::OpenGLShader>(textureShader);
        openGLShader->Bind();
        openGLShader->UploadUniformInt("u_Texture", 0);
    }

    virtual void OnDetach() override
    {
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Framerate");
        ImGui::Text("%.2f FPS", framerate);
        ImGui::End();

        ImGui::Begin("Settings");
        ImGui::ColorPicker4("Color", glm::value_ptr(gridColor));
        ImGui::End();
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        Hazel::Info("Sandbox creation");
        PushLayer(new TestLayer(GetWindow()));
    };

    // TEST
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
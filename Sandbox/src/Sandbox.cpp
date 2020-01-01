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

    Hazel::SharedPtr<Hazel::Shader> uniformShader;
    Hazel::SharedPtr<Hazel::Shader> textureShader;
    Hazel::SharedPtr<Hazel::VertexArray> squareVertexArray;
    Hazel::SharedPtr<Hazel::Texture2D> texture;
    Hazel::SharedPtr<Hazel::Texture2D> overlay;
    Hazel::OrthographicCamera camera = {{-1.6f, 1.6f, -0.9f, 0.9f}};
    glm::vec3 cameraPosition{0.0f};
    glm::vec3 gridPosition{0.0f};
    float cameraRotation = 0.0f;
    float cameraTranslationSpeed = 1.0f;
    float cameraRotationSpeed = 10.0f;
    double framerate = 0.0;
    glm::vec4 color = {0.2f, 0.3f, 0.8f, 1.0f};

public:
    TestLayer(Hazel::Window &parent)
        : parent(parent),
        renderer(parent)
    {
    }

    virtual void OnUpdate(Hazel::Timestep deltaTime) override
    {
        static std::vector<double> buffer(60, 0.0);
        double temp = 1.0 / deltaTime;
        buffer.erase(buffer.begin());
        buffer.push_back(temp);
        framerate = std::accumulate(buffer.begin(), buffer.end(), 0.0) / buffer.size();

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
        //cameraPosition = glm::clamp(cameraPosition, -1.0f, 1.0f);

        // Test rotate camera
        /*if (input.IsKeyPressed(Hazel::Key::A))
        {
            cameraRotation += 10 * cameraRotationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::D))
        {
            cameraRotation -= 10 * cameraRotationSpeed * deltaTime;
        }*/
        //cameraRotation = glm::clamp(cameraRotation, 0.0f, 360.0f);

        // Test moving grid
        if (input.IsKeyPressed(Hazel::Key::D))
        {
            gridPosition.x += cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::A))
        {
            gridPosition.x -= cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::W))
        {
            gridPosition.y += cameraTranslationSpeed * deltaTime;
        }
        if (input.IsKeyPressed(Hazel::Key::S))
        {
            gridPosition.y -= cameraTranslationSpeed * deltaTime;
        }

        // Set camera position
        camera.SetPosition(cameraPosition);
        camera.SetRotation(cameraRotation);

        // Render
        renderer.BeginScene(camera);

        auto openGLShader = std::dynamic_pointer_cast<Hazel::OpenGLShader>(uniformShader);

        openGLShader->Bind();
        openGLShader->UploadUniformFloat4("u_Color", color);

        // Test multiple triangles
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
        texture->Bind();
        renderer.Submit(textureShader, squareVertexArray, glm::mat4(1.0f));
        overlay->Bind();
        renderer.Submit(textureShader, squareVertexArray, glm::mat4(1.0f));

        renderer.EndScene();
    }

    virtual void OnAttach() override
    {
        Hazel::ObjectFactory &factory = parent.GetContext().GetFactory();
        squareVertexArray = factory.CreateVertexArray();

        Hazel::SharedPtr<Hazel::VertexBuffer> vertexBuffer(factory.CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f}));

        vertexBuffer->SetLayout({
            {Hazel::ShaderDataType::Float3, "a_Position"},
            {Hazel::ShaderDataType::Float2, "a_TexCoord"}});

        squareVertexArray->AddVertexBuffer(vertexBuffer);

        Hazel::SharedPtr<Hazel::IndexBuffer> indexBuffer(factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0}));
        squareVertexArray->SetIndexBuffer(indexBuffer);

        uniformShader = factory.CreateShader(vertexSource, fragmentSource);
        textureShader = factory.CreateShader("assets\\shaders\\Texture.glsl");
        texture = factory.CreateTexture2D("assets\\textures\\Test.jpg");
        overlay = factory.CreateTexture2D("assets\\textures\\TestOverlay.png");

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
        ImGui::Text("%f FPS", framerate);
        ImGui::End();

        ImGui::Begin("Settings");
        ImGui::ColorPicker4("Color", glm::value_ptr(color));
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
        PushLayer(new TestLayer(GetWindow()));
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
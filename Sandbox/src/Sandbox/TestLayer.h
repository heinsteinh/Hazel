#pragma once

#include "Hazel.h"

namespace Sandbox
{
    class TestLayer : public Hazel::Layer
    {
    private:
        Hazel::Window &parent;
        Hazel::Renderer renderer;

        Hazel::OrthographicCameraController cameraController;

        Hazel::ShaderLibrary library;
        Hazel::SharedPtr<Hazel::Shader> uniformShader;

        Hazel::SharedPtr<Hazel::VertexArray> textureVertexArray;
        Hazel::SharedPtr<Hazel::VertexArray> squareVertexArray;

        Hazel::SharedPtr<Hazel::Texture2D> texture;
        Hazel::SharedPtr<Hazel::Texture2D> overlay;

        glm::vec3 gridPosition{0.0f};
        glm::vec4 gridColor = {0.2f, 0.3f, 0.8f, 1.0f};

        double framerate = 0.0;
        bool showFps = true;
        bool showColor = true;

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
            if (e.GetKey() == Hazel::Key::I)
            {
                showFps = showColor = true;
            }
        }

        virtual void OnAttach() override
        {
            cameraController.SetRotationEnabled(true);

            Hazel::ObjectFactory &factory = parent.GetContext().GetFactory();

            textureVertexArray = factory.CreateVertexArray();
            squareVertexArray = factory.CreateVertexArray();

            auto vertexBuffer = factory.CreateVertexBuffer({
                -0.8f, -0.45f, 0.0f, 0.0f, 0.0f,
                 0.8f, -0.45f, 0.0f, 1.0f, 0.0f,
                 0.8f,  0.45f, 0.0f, 1.0f, 1.0f,
                -0.8f,  0.45f, 0.0f, 0.0f, 1.0f});
            vertexBuffer->SetLayout({
                {Hazel::ShaderDataType::Float3, "a_Position"},
                {Hazel::ShaderDataType::Float2, "a_TexCoord"}});

            auto vertexBuffer2 = factory.CreateVertexBuffer({
                -0.5f, -0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
                 0.5f,  0.5f, 0.0f,
                -0.5f,  0.5f, 0.0f});
            vertexBuffer2->SetLayout({{Hazel::ShaderDataType::Float3, "a_Position"}});

            textureVertexArray->AddVertexBuffer(vertexBuffer);
            squareVertexArray->AddVertexBuffer(vertexBuffer2);

            auto indexBuffer = factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0});
            textureVertexArray->SetIndexBuffer(indexBuffer);
            squareVertexArray->SetIndexBuffer(indexBuffer);

            uniformShader = factory.CreateShader("FlatColor", "assets\\shaders\\FlatColor.glsl");
            auto textureShader = library.Load("assets\\shaders\\Texture.glsl");
            texture = factory.CreateTexture2D("assets\\textures\\Test.jpg");
            overlay = factory.CreateTexture2D("assets\\textures\\TestOverlay.png");

            // TEST
            textureShader->Bind();
            //textureShader->Upd("u_Texture", 0);
        }

        virtual void OnDetach() override
        {
        }

        virtual void OnUpdate(Hazel::Timestep deltaTime) override
        {
            static double alpha = 0.05;
            static double previous = 0.0;
            double value = 1.0 / deltaTime.ToSeconds();
            framerate = alpha * value + (1.0 - alpha) * previous;
            previous = framerate;

            cameraController.OnUpdate(deltaTime);

            // Test moving grid
            static const float translationSpeed = 1.0f;
            auto &input = parent.GetInput();
            if (input.IsKeyPressed(Hazel::Key::Right))
            {
                gridPosition.x += translationSpeed * deltaTime.ToSeconds();
            }
            if (input.IsKeyPressed(Hazel::Key::Left))
            {
                gridPosition.x -= translationSpeed * deltaTime.ToSeconds();
            }
            if (input.IsKeyPressed(Hazel::Key::Up))
            {
                gridPosition.y += translationSpeed * deltaTime.ToSeconds();
            }
            if (input.IsKeyPressed(Hazel::Key::Down))
            {
                gridPosition.y -= translationSpeed * deltaTime.ToSeconds();
            }

            // Clear color
            parent.GetContext().GetDrawer().Clear();

            // Render
            renderer.BeginScene(cameraController.GetCamera());

            static const std::string uniformName = "u_Color";
            uniformShader->Bind();
            uniformShader->Put(uniformName, gridColor);

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
            renderer.Submit(textureShader, textureVertexArray, glm::mat4(1.0f));
            overlay->Bind();
            renderer.Submit(textureShader, textureVertexArray, glm::mat4(1.0f));

            renderer.EndScene();
        }

        virtual void OnImGuiRender() override
        {
            if (showFps)
            {
                ImGui::Begin("Framerate", &showFps);
                ImGui::Text("%.2f FPS", framerate);
                ImGui::End();
            }
            if (showColor)
            {
                ImGui::Begin("Settings", &showColor);
                ImGui::ColorPicker4("Color", glm::value_ptr(gridColor));
                ImGui::End();
            }
        }
    };
}
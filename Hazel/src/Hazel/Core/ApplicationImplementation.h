#pragma once

#include <memory>

#include "Logger.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "LayerStack.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Utils/Reversed.h"

// TEST
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/VertexBuffer.h"
#include "Hazel/Renderer/IndexBuffer.h"
#include "Hazel/Renderer/BufferLayout.h"
#include "Hazel/Renderer/VertexArray.h"

namespace Hazel
{
    class ApplicationImplementation : public EventListener
    {
    private:
        std::unique_ptr<Window> window;
        ImGuiLayer *imguiLayer;
        bool running = false;
        LayerStack layers;

        // TEST
        std::shared_ptr<Shader> shader;

        std::shared_ptr<VertexArray> triangleVertexArray;
        std::shared_ptr<VertexArray> squareVertexArray;

    public:
        ApplicationImplementation()
            : window(Window::Create()),
            imguiLayer(new Hazel::ImGuiLayer(*window.get()))
        {
            Init();
        }

        inline const Window &GetWindow()
        {
            return *window.get();
        }

        inline void Run()
        {
            CoreInfo("Application started.");
            running = true;
            while (running)
            {
                Update();
            }
            CoreInfo("Application stopped.");
        }

        inline void Quit()
        {
            running = false;
        }

        inline void PushLayer(Layer *layer)
        {
            layers.PushLayer(layer);
        }

        inline void PushOverlay(Layer *overlay)
        {
            layers.PushOverlay(overlay);
        }

        virtual void OnEvent(Event &e) override
        {
            CoreDebug("{}", e);
            for (Layer *layer : layers)
            {
                EventDispatcher(layer).Dispatch(e);
            }
        }

        virtual void OnWindowClosed(WindowClosedEvent &e) override
        {
            Quit();
        }

    private:
        // TEST
        inline void TestTriangle()
        {
            float vertices[] = {
                -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
            };

            triangleVertexArray.reset(VertexArray::Create());

            std::shared_ptr<VertexBuffer> vertexBuffer;
            vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
            vertexBuffer->SetLayout({
                {ShaderDataType::Float3, "a_Position"},
                {ShaderDataType::Float4, "a_Color"}});

            triangleVertexArray->AddVertexBuffer(vertexBuffer);

            unsigned int indexes[] = {0, 1, 2};

            std::shared_ptr<IndexBuffer> indexBuffer;
            indexBuffer.reset(IndexBuffer::Create(indexes, sizeof(indexes) / sizeof(int)));

            triangleVertexArray->SetIndexBuffer(indexBuffer);

            squareVertexArray.reset(VertexArray::Create());

            std::string vertexSource = R"(
                #version 330 core

                layout(location = 0) in vec3 a_Position;
                layout(location = 1) in vec4 a_Color;

                out vec3 v_Position;
                out vec4 v_Color;

                void main()
                {
                    v_Position = a_Position;
                    v_Color = a_Color;
                    gl_Position = vec4(a_Position, 1.0);
                }

            )";
            std::string fragmentSource = R"(
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

            shader.reset(Shader::Create(vertexSource, fragmentSource));
        }

        inline void Init()
        {
            CoreDebug("Application initialization.");
            SetupWindow();
            PushOverlay(imguiLayer);

            // TEST
            TestTriangle();

            CoreDebug("Application initialized.");
        }

        inline void SetupWindow()
        {
            CoreDebug("Main window setup started.");
            window->SetEventListener(this);
            CoreDebug("Main window setup done.");
        }

        inline void Update()
        {
            UpdateLayers();

            // TEST
            shader->Bind();
            triangleVertexArray->Bind();
            glDrawElements(
                GL_TRIANGLES,
                (int)triangleVertexArray->GetIndexBuffer()->GetCount(),
                GL_UNSIGNED_INT,
                nullptr);

            RenderImGui();
            window->OnUpdate();
        }

        inline void UpdateLayers()
        {
            CoreTrace("Update Layers");
            for (Layer *layer : Reversed(layers))
            {
                layer->OnUpdate();
            }
        }

        inline void RenderImGui()
        {
            CoreTrace("Render ImGui");
            imguiLayer->Begin();
            for (Layer *layer : Reversed(layers))
            {
                layer->OnImGuiRender();
            }
            imguiLayer->End();
        }
    };
}
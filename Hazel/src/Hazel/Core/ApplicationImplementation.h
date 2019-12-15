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
        unsigned int vertexArray;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<VertexBuffer> vertexBuffer;
        std::unique_ptr<IndexBuffer> indexBuffer;

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
            glGenVertexArrays(1, &vertexArray);
            glBindVertexArray(vertexArray);

            float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
                 0.0f,  0.5f, 0.0f
            };

            int indexes[] = {0, 1, 2};

            vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

            indexBuffer.reset(IndexBuffer::Create(indexes, sizeof(indexes)));

            std::string vertexSource = R"(
                #version 330 core

                layout(location = 0) in vec3 a_Position;

                out vec3 v_Position;

                void main()
                {
                    v_Position = a_Position;
                    gl_Position = vec4(a_Position, 1.0);
                }

            )";
            std::string fragmentSource = R"(
                #version 330 core

                layout(location = 0) out vec4 color;

                in vec3 v_Position;

                void main()
                {
                    color = vec4(v_Position * 0.5 + 0.5, 1.0);
                }

            )";

            shader = std::make_unique<Shader>(vertexSource, fragmentSource);
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
            CoreDebug("Main window setup stopped.");
        }

        inline void Update()
        {
            UpdateLayers();

            // TEST
            shader->Bind();
            glBindVertexArray(vertexArray);
            glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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
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
        static inline unsigned int GetOpenGLType(const ShaderDataType &type)
        {
            static const std::unordered_map<const ShaderDataType *, unsigned int> types = {
                {&ShaderDataType::Float, GL_FLOAT},
                {&ShaderDataType::Float2, GL_FLOAT},
                {&ShaderDataType::Float3, GL_FLOAT},
                {&ShaderDataType::Float4, GL_FLOAT},
                {&ShaderDataType::Matrix3, GL_FLOAT},
                {&ShaderDataType::Matrix4, GL_FLOAT},
                {&ShaderDataType::Int, GL_INT},
                {&ShaderDataType::Int2, GL_INT},
                {&ShaderDataType::Int3, GL_INT},
                {&ShaderDataType::Int4, GL_INT},
                {&ShaderDataType::Bool, GL_BOOL}
            };
            auto i = types.find(&type);
            if (i == types.end())
            {
                CoreError("Unknown shader data type: {}", type.GetSize());
                return 0;
            }
            return i->second;
        }

        // TEST
        inline void TestTriangle()
        {
            glGenVertexArrays(1, &vertexArray);
            glBindVertexArray(vertexArray);

            float vertices[] = {
                -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
            };

            vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
            vertexBuffer->SetLayout({
                {ShaderDataType::Float3, "a_Position"},
                {ShaderDataType::Float4, "a_Color"}
            });

            const auto &layout = vertexBuffer->GetLayout();
            for (int i = 0; i < layout.GetSize(); i++)
            {
                const auto &element = layout[i];
                glEnableVertexAttribArray(i);
                glVertexAttribPointer(
                    i,
                    (int)element.GetComponentCount(),
                    GetOpenGLType(element.GetType()),
                    element.IsNormalized() ? GL_TRUE : GL_FALSE,
                    (int)layout.GetStride(),
                    (const void *)element.GetOffset());
            }

            int indexes[] = {0, 1, 2};
            indexBuffer.reset(IndexBuffer::Create(indexes, sizeof(indexes) / sizeof(int)));

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
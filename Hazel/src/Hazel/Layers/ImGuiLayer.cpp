#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    ImGuiLayer::ImGuiLayer()
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    const std::string &ImGuiLayer::GetName() const
    {
        static const std::string name = "ImGuiLayer";
        return name;
    }

    void ImGuiLayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGuiIO &io = ImGui::GetIO();

        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;

        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;

        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;

        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;

        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;

        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;

        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;

        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;

        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;

        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;

        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;

        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;

        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;

        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;

        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;

        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;

        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;

        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;

        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;

        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;

        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init();
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGui::GetIO().DisplaySize = {1280, 720};

        double time = glfwGetTime();
        ImGui::GetIO().DeltaTime = this->time > 0 ? (float)(time - this->time) : (1.0f / 60.0f);
        this->time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent &e)
    {
        ImGui::GetIO().MouseDown[static_cast<int>(e.GetButton())] = true;
    }

    void ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent &e)
    {
        ImGui::GetIO().MouseDown[static_cast<int>(e.GetButton())] = false;
    }

    void ImGuiLayer::OnMouseMoved(MouseMovedEvent &e)
    {
        ImGui::GetIO().MousePos = {(float)e.GetXPosition(), (float)e.GetYPosition()};
    }

    void ImGuiLayer::OnMouseScrolled(MouseScrolledEvent &e)
    {
        ImGui::GetIO().MouseWheelH += (float)e.GetXOffset();
        ImGui::GetIO().MouseWheel += (float)e.GetYOffset();
    }

    void ImGuiLayer::OnKeyPressed(KeyPressedEvent &e)
    {
        ImGuiIO io = ImGui::GetIO();
        io.KeysDown[static_cast<int>(e.GetKey())] = true;
        io.KeyCtrl = io.KeysDown[static_cast<int>(Key::LeftControl)]
            || io.KeysDown[static_cast<int>(Key::RightControl)];
        io.KeyShift = io.KeysDown[static_cast<int>(Key::LeftShift)]
            || io.KeysDown[static_cast<int>(Key::RightShift)];
        io.KeyAlt = io.KeysDown[static_cast<int>(Key::LeftAlt)]
            || io.KeysDown[static_cast<int>(Key::RightAlt)];
        io.KeySuper = io.KeysDown[static_cast<int>(Key::LeftSuper)]
            || io.KeysDown[static_cast<int>(Key::RightSuper)];
    }

    void ImGuiLayer::OnKeyReleased(KeyReleasedEvent &e)
    {
        ImGui::GetIO().KeysDown[static_cast<int>(e.GetKey())] = false;
    }

    void ImGuiLayer::OnKeyTyped(KeyTypedEvent &e)
    {
        ImGui::GetIO().AddInputCharacter((ImWchar)e.GetKey());
    }

    void ImGuiLayer::OnWindowResized(WindowResizedEvent &e)
    {
        ImGui::GetIO().DisplaySize = {(float)e.GetWidth(), (float)e.GetHeight()};
        ImGui::GetIO().DisplayFramebufferScale = {1, 1};
        glViewport(0, 0, e.GetWidth(), e.GetHeight());
    }
}
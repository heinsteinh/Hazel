#include "ImGuiLayer.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    static inline auto GetGlfwWindow(const Window &window)
    {
        return static_cast<GLFWwindow *>(window.GetNativeWindow());
    }

    ImGuiLayer::ImGuiLayer(const Window &parent)
        : parent(parent)
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    const std::string &ImGuiLayer::GetName() const
    {
        static const std::string name = "ImGui";
        return name;
    }

    void ImGuiLayer::OnAttach()
    {
        Init();
    }

    void ImGuiLayer::OnDetach()
    {
        Shutdown();
    }

    void ImGuiLayer::OnUpdate()
    {
    }

    void ImGuiLayer::OnImGuiRender()
    {
        static bool open = true;
        ImGui::ShowDemoWindow(&open);
    }

    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        UpdatePlatforms();
    }

    void ImGuiLayer::Init()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        SetupConfigFlags();
        ImGui_ImplGlfw_InitForOpenGL(GetGlfwWindow(parent), true);
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void ImGuiLayer::SetupConfigFlags()
    {
        ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_NavEnableKeyboard
            | ImGuiConfigFlags_DockingEnable
            | ImGuiConfigFlags_ViewportsEnable;
        ImGui::GetStyle().WindowRounding = 0.0f;
        ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    void ImGuiLayer::UpdatePlatforms()
    {
        if (!(ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
        {
            return;
        }
        GLFWwindow *backup = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup);
    }

    void ImGuiLayer::Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
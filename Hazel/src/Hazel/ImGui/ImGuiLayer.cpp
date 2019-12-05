#include "ImGuiLayer.h"

#include "imgui.h"
#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_glfw.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hazel
{
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
        ImGui::GetIO().DisplaySize = {(float)parent.GetWidth(), (float)parent.GetHeight()};
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(glfwGetCurrentContext());
        }
    }

    void ImGuiLayer::Init()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard
            | ImGuiConfigFlags_DockingEnable
            | ImGuiConfigFlags_ViewportsEnable;
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::GetStyle().WindowRounding = 0.0f;
            ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
        ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow *>(parent.GetNativeWindow()), true);
        ImGui_ImplOpenGL3_Init();
    }

    void ImGuiLayer::Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
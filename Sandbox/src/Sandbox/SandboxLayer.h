#pragma once

#include "Hazel.h"
#include "Hazel/ImGui/ImGuiDockSpace.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:
		float renderTime = 0.0f;
		glm::vec2 bottomLeft{0.0f};
		Hazel::Size size{2560.0f, 1664.0f};

		Hazel::Renderer2D renderer;
		Hazel::WindowProperties &window;
		Hazel::Input &input;
		Hazel::RenderApiFactory &factory;
		Hazel::OrthographicCamera camera;
		Hazel::OrthographicCameraController controller;
		Hazel::EventDispatcher dispatcher;
		Hazel::DrawData drawData;
		Hazel::ImGuiDockSpace dockspace;
		std::shared_ptr<Hazel::Texture> spriteSheet;

	public:
		SandboxLayer(Hazel::Context &context);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnKeyPressed(Hazel::KeyPressEvent &e) override;
		virtual void OnMouseButtonPressed(Hazel::MouseButtonPressEvent &e) override;
	};
}
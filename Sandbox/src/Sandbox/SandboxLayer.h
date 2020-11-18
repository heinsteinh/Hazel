#pragma once

#include "Hazel.h"
#include "ImGuiDockSpace.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:
		float renderTime = 0.0f;
		glm::vec2 bottomLeft{0.0f};
		Hazel::Size size{2560.0f, 1664.0f};

		std::shared_ptr<Hazel::Renderer2D> renderer;
		Hazel::OrthographicCamera camera;
		Hazel::OrthographicCameraController cameraController;
		Hazel::DrawData drawData;
		ImGuiDockSpace dockspace;
		std::shared_ptr<Hazel::Texture> spriteSheet;

	public:
		SandboxLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
	};
}
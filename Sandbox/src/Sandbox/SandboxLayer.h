#pragma once

#include "Hazel.h"
#include "Hazel/Geometry/ScreenTransform.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:

		float renderTime = 0.0f;
		int nParticles = 5;
		int maxParticles = 1000;
		glm::vec2 bottomLeft{0.0f};
		Hazel::Size size{2560.0f, 1664.0f};

		Hazel::Renderer2D renderer;
		Hazel::ApplicationSettings &settings;
		Hazel::WindowProperties &window;
		Hazel::Input &input;
		Hazel::RenderApiFactory &factory;
		Hazel::OrthographicCamera camera;
		Hazel::ScreenTransform screenTransform;
		Hazel::OrthographicCameraController controller;
		Hazel::EventDispatcher dispatcher;
		Hazel::ParticleSystem particleSystem;
		Hazel::ParticleInfo particleInfo;
		Hazel::ParticleInfo defaultInfo;
		Hazel::DrawData drawData;
		std::shared_ptr<Hazel::Texture2D> spriteSheet;

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
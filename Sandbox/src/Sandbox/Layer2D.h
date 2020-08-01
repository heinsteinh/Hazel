#pragma once

#include "Hazel.h"

namespace Sandbox
{
	class Layer2D : public Hazel::Layer
	{
	private:
		Hazel::ApplicationSettings &settings;
		Hazel::Renderer2D renderer;
		Hazel::Input &input;
		Hazel::RenderApiFactory &factory;
		Hazel::OrthographicCamera camera;
		Hazel::OrthographicCameraController controller;
		Hazel::EventDispatcher dispatcher;

		float framerate = 0.0f;

	public:
		Layer2D(Hazel::Context &context);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnKeyPressed(Hazel::KeyPressEvent &e) override;
	};
}
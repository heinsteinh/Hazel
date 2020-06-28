#pragma once

#include "Hazel.h"
#include "Hazel/Rendering/Renderer/RectangularSprite.h"

namespace Sandbox
{
	class Layer2D : public Hazel::Layer
	{
	private:
		Hazel::Application &application;
		Hazel::Renderer2D renderer;
		Hazel::OrthographicCameraController cameraController;
		std::vector<Hazel::RectangularSprite> rectangles;

		float framerate = 0.0f;

		glm::vec4 color = {1.0f, 0.0f, 0.0f, 1.0f};

		std::shared_ptr<Hazel::Texture2D> texture;
		Hazel::Transform transform;

		bool showImGui = true;
		bool showFps = true;
		bool showColorPicker = true;

	public:
		Layer2D(Hazel::Application &application);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnKeyPressed(Hazel::KeyPressEvent &e) override;
	};
}
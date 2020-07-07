#pragma once

#include "Hazel.h"
#include "Hazel/Rendering/Batch/RectangularSprite.h"

namespace Sandbox
{
	class Layer2D : public Hazel::Layer
	{
	private:
		Hazel::ApplicationSettings &settings;
		Hazel::Renderer2D renderer;
		Hazel::Input &input;
		Hazel::RenderApiFactory &factory;
		Hazel::OrthographicCameraController cameraController;
		std::vector<Hazel::RectangularSprite> rectangles;

		float framerate = 0.0f;
		float speed = 1.0f;

		glm::vec4 color{1.0f};

		std::shared_ptr<Hazel::Texture2D> texture;

		bool showImGui = true;
		bool showFps = true;
		bool showColorPicker = true;
		bool showTransform = true;
		bool showCamera = true;

		glm::vec2 translation{0.0f};
		float rotation = 0.0f;
		glm::vec2 scale{1.0f};

		glm::vec2 cameraTranslation{0.0f};
		float cameraRotation = 0.0f;
		float zoomLevel = 1.0f;

	public:
		Layer2D(Hazel::Context &context);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
		virtual void OnWindowResized(Hazel::WindowResizeEvent &e) override;
		virtual void OnKeyPressed(Hazel::KeyPressEvent &e) override;
		virtual void OnMouseScrolled(Hazel::MouseScrollEvent &e) override;
	};
}
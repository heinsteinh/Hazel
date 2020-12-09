#pragma once

#include "Hazel.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:
		bool blockKeyboard = false;
		bool blockMouse = false;
		glm::vec2 viewport{0.0f};
		glm::vec2 position{0.0f};
		Hazel::InfoPanel infoPanel;
		Hazel::TransformPanel transformPanel;
		Hazel::TextureRegionPanel textureRegionPanel;
		Hazel::RendererInfoPanel rendererInfoPanel;

		Hazel::BatchInfo rendererInfo;
		std::shared_ptr<Hazel::Renderer2D> renderer;
		Hazel::Rectangle region;
		Hazel::SubTexture spriteSheet;
		std::shared_ptr<Hazel::Scene> scene;
		Hazel::Entity square;
		Hazel::Entity camera1;
		Hazel::Entity camera2;

	public:
		SandboxLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override;
	};
}
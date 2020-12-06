#pragma once

#include "Hazel.h"
#include "EditorWindow.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	private:
		bool blockKeyboard = false;
		bool blockMouse = false;
		float angle = 0.0f;
		glm::vec2 viewport{0.0f};
		InfoPanel infoPanel;
		TransformPanel transformPanel;
		TextureRegionPanel textureRegionPanel;
		RendererInfoPanel rendererInfoPanel;

		BatchInfo rendererInfo;
		std::shared_ptr<Renderer2D> renderer;
		std::shared_ptr<Framebuffer> framebuffer;
		EditorWindow editorWindow;
		std::shared_ptr<Mesh> squareMesh;
		Rectangle region;
		SubTexture spriteSheet;
		Scene scene;
		Entity square;
		Entity camera1;
		Entity camera2;

	public:
		EditorLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event &e) override;
	};
}
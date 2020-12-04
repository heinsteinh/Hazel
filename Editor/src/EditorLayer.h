#pragma once

#include "Hazel.h"
#include "ImGuiDockSpace.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	private:
		float renderTime = 0.0f;
		int maxVertices = 40000;
		int maxIndices = 60000;
		glm::vec2 bottomLeft{0.0f};
		glm::vec2 size{2560.0f, 1664.0f};
		bool blockKeyboard = false;
		bool blockMouse = false;
		float angle = 0.0f;
		glm::vec2 viewport{0.0f};
		Hazel::TransformUI transform;

		std::shared_ptr<Renderer2D> renderer;
		std::shared_ptr<Framebuffer> framebuffer;
		ImGuiDockSpace dockspace;
		std::shared_ptr<Mesh> squareMesh;
		SubTexture spriteSheet;
		Scene scene;
		Entity square;
		Entity camera1;
		Entity camera2;

	public:
		EditorLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
	};
}
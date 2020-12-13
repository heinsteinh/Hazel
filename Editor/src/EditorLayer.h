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
		Rectangle viewport;
		SceneHierarchyPanel scenePanel;
		InfoPanel infoPanel;
		RendererStatisticsPanel rendererStatisticsPanel;
		BatchInfoPanel batchInfoPanel;

		bool useCamera1 = true;
		BatchInfo rendererInfo;
		std::shared_ptr<Renderer2D> renderer;
		std::shared_ptr<Framebuffer> framebuffer;
		EditorWindow editorWindow;
		Rectangle region;
		SubTexture spriteSheet;
		std::shared_ptr<Scene> scene;
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
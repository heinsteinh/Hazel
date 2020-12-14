#pragma once

#include "Hazel.h"

#include "Editor/MainWindow/EditorWindow.h"
#include "Editor/ScenePanels/SceneHierarchyPanel.h"
#include "Editor/InfoPanels/FpsPanel.h"
#include "Editor/InfoPanels/RendererStatisticsPanel.h"
#include "Editor/InfoPanels/BatchPanel.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	private:
		EditorWindow editorWindow;
		SceneHierarchyPanel scenePanel;
		FpsPanel fpsPanel;
		RendererStatisticsPanel rendererStatisticsPanel;
		BatchPanel batchPanel;

		Rectangle viewport;
		bool useCamera1 = true;
		BatchInfo rendererInfo;
		std::shared_ptr<Renderer2D> renderer;
		std::shared_ptr<Framebuffer> framebuffer;
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
		virtual void OnGui() override;
		virtual void OnEvent(Event &e) override;
	};
}
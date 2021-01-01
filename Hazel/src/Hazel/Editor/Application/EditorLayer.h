#pragma once

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Rendering/Textures/TextureManager.h"
#include "Hazel/Scene/Manager/SceneManager.h"
#include "Hazel/Editor/MainWindow/EditorWindow.h"
#include "Hazel/Editor/ScenePanels/SceneHierarchyPanel.h"
#include "Hazel/Editor/InfoPanels/FpsPanel.h"
#include "Hazel/Editor/InfoPanels/RendererStatisticsPanel.h"
#include "Hazel/Editor/InfoPanels/BatchPanel.h"
#include "EditorMenu.h"
#include "SceneFileDialog.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	private:
		EditorWindow editorWindow;
		EditorMenu menu;
		SceneHierarchyPanel scenePanel;
		FpsPanel fpsPanel;
		RendererStatisticsPanel rendererStatisticsPanel;
		BatchPanel batchPanel;

		Rectangle viewport;
		bool useCamera1 = true;
		BatchInfo rendererInfo;
		std::shared_ptr<Renderer2D> renderer;
		std::shared_ptr<TextureManager> textureManager;
		std::shared_ptr<Framebuffer> framebuffer;
		SubTexture spriteSheet;
		SceneManager sceneManager;
		Scene scene;
		Entity camera1;
		Entity camera2;
		SceneFileDialog fileDialog;

	public:
		EditorLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnGui() override;
		virtual void OnEvent(Event &e) override;
	};
}
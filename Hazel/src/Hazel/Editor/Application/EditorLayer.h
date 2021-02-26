#pragma once

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Scene/Manager/SceneManager.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	private:
		Entity selectedEntity;
		Box2D viewport;
		bool useCamera1 = true;
		RendererInfo rendererInfo;
		std::shared_ptr<Framebuffer> framebuffer;
		SceneManager sceneManager;
		std::shared_ptr<Scene> scene;
		Entity camera1;
		Entity camera2;
		FileDialog fileDialog;

	public:
		EditorLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnGui() override;
		virtual void OnEvent(Event &e) override;
	};
}
#pragma once

#include <memory>

#include "Hazel/Core/Application/ApplicationLayer.h"
#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Scene/Scene/Entity.h"

namespace Hazel
{
	class SceneManager;
	class Scene;

	class EditorLayer : public ApplicationLayer
	{
	private:
		Entity selectedEntity;
		Box2D viewport;
		bool useCamera1 = true;
		RendererInfo rendererInfo;
		std::shared_ptr<Framebuffer> framebuffer;
		std::unique_ptr<SceneManager> sceneManager;
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
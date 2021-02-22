#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "SceneManagerContext.h"

namespace Hazel
{
	class SceneManager
	{
	private:
		SceneManagerContext context;

	public:
		std::shared_ptr<Scene> CreateScene(const std::string &name);
		void ResetRenderer(const RendererInfo &rendererInfo);
		void OnAttach(Layer &layer, const RendererInfo &rendererInfo = {});
		void OnPlay(Scene &scene);
		void OnUpdate(Scene &scene);
		void OnRender(Scene &scene, const std::shared_ptr<Framebuffer> &framebuffer = nullptr);
		void OnViewportResize(Scene &scene, const Box2D &viewport);
		void OnEvent(Scene &scene, Event &e);

		Renderer2D &GetRenderer() const
		{
			return *context.Renderer;
		}

		const AssetManager &GetAssetManager() const
		{
			return context.AssetManager;
		}

		AssetManager &GetAssetManager()
		{
			return context.AssetManager;
		}
	};
}
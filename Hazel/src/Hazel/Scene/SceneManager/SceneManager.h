#pragma once

#include <memory>
#include <vector>

#include "Hazel/Core/Application/ApplicationLayer.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Scene/Assets/AssetManager.h"
#include "Hazel/Scene/ComponentSystem/ComponentSystems.h"
#include "Hazel/Scene/ComponentManager/ComponentManagers.h"

namespace Hazel
{
	class SceneManager
	{
	private:
		ApplicationView application;
		ApplicationLayer *applicationLayer;
		std::unique_ptr<Renderer2D> renderer;
		AssetManager assetManager;
		ComponentSystems componentSystems;
		ComponentManagers componentManagers;

	public:
		SceneManager(ApplicationLayer &applicationLayer, const RendererInfo &info = {})
			: application(applicationLayer.GetApplication()),
			applicationLayer(&applicationLayer),
			renderer(std::make_unique<Renderer2D>(info)),
			componentSystems(*this),
			componentManagers(*this)
		{
		}

		ApplicationView GetApplication() const
		{
			return application;
		}

		ApplicationLayer &GetApplicationLayer() const
		{
			return *applicationLayer;
		}

		Renderer2D &GetRenderer() const
		{
			return *renderer;
		}

		void ResetRenderer(const RendererInfo &info)
		{
			renderer = std::make_unique<Renderer2D>(info);
		}

		const AssetManager &GetAssetManager() const
		{
			return assetManager;
		}

		AssetManager &GetAssetManager()
		{
			return assetManager;
		}

		const ComponentSystems &GetComponentSystems() const
		{
			return componentSystems;
		}

		void AddComponentSystem(std::unique_ptr<ComponentSystem> componentSystem)
		{
			componentSystems.AddComponentSystem(std::move(componentSystem));
		}

		const ComponentManagers &GetComponentManagers() const
		{
			return componentManagers;
		}

		void AddComponentManager(std::unique_ptr<ComponentManager> componentManager)
		{
			componentManagers.AddComponentManager(std::move(componentManager));
		}
	};
}
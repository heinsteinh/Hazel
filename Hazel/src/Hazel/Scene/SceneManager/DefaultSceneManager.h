#pragma once

#include <memory>

#include "Hazel/Scene/Components/Camera/CameraSystem.h"
#include "Hazel/Scene/Components/Camera/CameraManager.h"
#include "Hazel/Scene/Components/Particle/ParticleSystem.h"
#include "Hazel/Scene/Components/Particle/ParticleManager.h"
#include "Hazel/Scene/Components/Script/ScriptSystem.h"
#include "Hazel/Scene/Components/Script/ScriptManager.h"
#include "Hazel/Scene/Components/Sprite/SpriteSystem.h"
#include "Hazel/Scene/Components/Sprite/SpriteManager.h"
#include "SceneManager.h"

namespace Hazel
{
	class DefaultSceneManager
	{
	public:
		static std::unique_ptr<SceneManager> Create(ApplicationLayer &applicationLayer, const RendererInfo &info = {})
		{
			auto manager = std::make_unique<SceneManager>(applicationLayer, info);
			manager->AddComponentSystem(std::make_unique<CameraSystem>());
			manager->AddComponentManager(std::make_unique<CameraManager>());
			manager->AddComponentSystem(std::make_unique<ParticleSystem>());
			manager->AddComponentManager(std::make_unique<ParticleManager>());
			manager->AddComponentSystem(std::make_unique<ScriptSystem>());
			manager->AddComponentManager(std::make_unique<ScriptManager>());
			manager->AddComponentSystem(std::make_unique<SpriteSystem>());
			manager->AddComponentManager(std::make_unique<SpriteManager>());
			return manager;
		}
	};
}
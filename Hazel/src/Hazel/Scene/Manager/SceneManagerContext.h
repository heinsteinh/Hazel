#pragma once

#include <memory>

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "AssetManager.h"

namespace Hazel
{
	struct SceneManagerContext
	{
		Layer *Layer = nullptr;
		std::unique_ptr<Renderer2D> Renderer;
		AssetManager AssetManager;
	};
}
#pragma once

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Rendering/Textures/TextureManager.h"

namespace Hazel
{
	struct SceneManagerContext
	{
		Layer *Layer = nullptr;
		std::unique_ptr<Renderer2D> Renderer;
		std::unique_ptr<TextureManager> TextureManager;
	};
}
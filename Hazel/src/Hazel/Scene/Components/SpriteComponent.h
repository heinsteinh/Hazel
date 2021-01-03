#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Rendering/Textures/SubTexture.h"
#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	struct SpriteComponent
	{
		glm::vec4 Color{1.0f};
		std::string TextureFilename;
		SubTexture Texture;
	};

	template<>
	inline void EntityListener::OnComponentAdded(Entity entity, SpriteComponent &component)
	{
		if (!component.TextureFilename.empty())
		{
			component.Texture = entity.GetTextureManager().Load(component.TextureFilename);
		}
	}
}
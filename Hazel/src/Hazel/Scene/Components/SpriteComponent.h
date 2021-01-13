#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Rendering/Materials/Material.h"
#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	struct SpriteComponent
	{
		Material Material;
		std::string TextureFilename;
	};

	template<>
	inline void EntityListener::OnComponentAdded(Entity entity, SpriteComponent &component)
	{
		if (!component.TextureFilename.empty())
		{
			component.Material.Texture = entity.GetTextureManager().Load(component.TextureFilename);
		}
		component.Material.Shader = entity.GetRenderer().GetDefaultShader();
	}
}
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
	};

	template<>
	inline void EntityListener::OnComponentAdded(Entity entity, SpriteComponent &component)
	{
		if (!component.Material.Shader)
		{
			component.Material.Shader = entity.GetRenderer().GetDefaultShader();
		}
	}
}
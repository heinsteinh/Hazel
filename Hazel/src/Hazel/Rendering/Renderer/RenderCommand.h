#pragma once

#include <memory>

#include "glm/glm.hpp"

#include "Hazel/Rendering/Mesh/Mesh.h"
#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Rendering/Materials/Material.h"

namespace Hazel
{
	struct RenderCommand
	{
		const Mesh *Mesh = nullptr;
		const Transform *Transform = nullptr;
		const glm::vec4 *Color = nullptr;
		const SubTexture *Texture = nullptr;
		const std::shared_ptr<Shader> *Shader = nullptr;

		bool IsValid() const
		{
			return Mesh && Shader && *Shader;
		}
	};
}
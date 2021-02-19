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
		std::shared_ptr<Mesh> Mesh;
		Transform Transform;
		glm::vec4 Color{1.0f};
		SubTexture Texture;
		std::shared_ptr<Shader> Shader;
		bool Transparency = false;

		bool IsValid() const
		{
			return Mesh && Shader;
		}
	};
}
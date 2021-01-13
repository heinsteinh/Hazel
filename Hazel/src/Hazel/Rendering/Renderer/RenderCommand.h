#pragma once

#include <memory>

#include "glm/glm.hpp"

#include "Hazel/Rendering/Meshes/Mesh.h"
#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Rendering/Materials/Material.h"

namespace Hazel
{
	struct RenderCommand
	{
		const Mesh *Mesh = nullptr;
		const Transform *Transform = nullptr;
		const Material *Material = nullptr;
	};
}
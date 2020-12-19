#pragma once

#include "Mesh.h"
#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Rendering/Textures/SubTexture.h"

namespace Hazel
{
	struct DrawData
	{
		const Mesh *Mesh = nullptr;
		const Transform *Transform = nullptr;
		const SubTexture *Texture = nullptr;
		const glm::vec4 *Color = nullptr;

		glm::vec3 ApplyTransform(const glm::vec3 &position) const
		{
			return Transform ? Transform->Apply(position) : position;
		}

		Hazel::Texture *GetTexture() const
		{
			return Texture ? Texture->GetSource() : nullptr;
		}

		glm::vec2 GetTextureCoordinates(const glm::vec2 &coordinates) const
		{
			return Texture ? Texture->GetSourceCoordinates(coordinates) : coordinates;
		}

		glm::vec4 GetColor(const VertexInfo &info) const
		{
			return Color ? *Color * info.Color : info.Color;
		}
	};
}
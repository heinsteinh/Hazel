#pragma once

#include "Mesh.h"
#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct DrawData
	{
		const Mesh *Mesh = nullptr;
		const glm::mat4 *Transform = nullptr;
		const SubTexture *Texture = nullptr;

		Hazel::Texture *GetTexture() const
		{
			return Texture ? Texture->GetSource() : nullptr;
		}

		glm::vec4 ApplyTransform(const glm::vec4 &position) const
		{
			return Transform ? *Transform * position : position;
		}

		glm::vec2 GetTextureCoordinates(const glm::vec2 &coordinates) const
		{
			return Texture ? Texture->GetSourceCoordinates(coordinates) : coordinates;
		}
	};
}
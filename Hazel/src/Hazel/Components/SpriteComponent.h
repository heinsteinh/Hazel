#pragma once

namespace Hazel
{
	struct SpriteComponent
	{
		glm::vec4 Color{1.0f};

		SpriteComponent() = default;

		SpriteComponent(const glm::vec4 &color)
			: Color(color)
		{
		}
	};
}
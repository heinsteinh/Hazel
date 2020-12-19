#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/GraphicsContext/PrimitiveTopology.h"

namespace Hazel
{
	class OpenGLPrimitiveTopology
	{
	public:
		static constexpr int GetPrimitiveTopology(PrimitiveTopology primitiveTopology)
		{
			switch (primitiveTopology)
			{
			case PrimitiveTopology::Triangles:
				return GL_TRIANGLES;
			case PrimitiveTopology::Lines:
				return GL_LINES;
			case PrimitiveTopology::Points:
				return GL_POINTS;
			case PrimitiveTopology::Patches:
				return GL_PATCHES;
			}
			return GL_TRIANGLES;
		}
	};
}
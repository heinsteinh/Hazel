#pragma once

#include "glad/glad.h"

#include "Hazel/Graphics/PrimitiveType.h"

namespace Hazel
{
	class OpenGLPrimitiveType
	{
	public:
		static constexpr int GetPrimitiveType(PrimitiveType primitiveType)
		{
			switch (primitiveType)
			{
			case PrimitiveType::Triangles:
				return GL_TRIANGLES;
			case PrimitiveType::Lines:
				return GL_LINES;
			case PrimitiveType::Points:
				return GL_POINTS;
			case PrimitiveType::Patches:
				return GL_PATCHES;
			}
			return GL_TRIANGLES;
		}
	};
}
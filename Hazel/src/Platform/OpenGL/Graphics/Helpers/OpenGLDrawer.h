#pragma once

#include "glad/glad.h"

#include "Hazel/Geometry/Rectangle.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexFormat.h"
#include "OpenGLPrimitiveType.h"

namespace Hazel
{
	class OpenGLDrawer
	{
	public:
		static inline void SetViewport(const Rectangle &viewport)
		{
			glViewport(
				static_cast<int>(viewport.Left),
				static_cast<int>(viewport.Bottom),
				static_cast<int>(viewport.GetWidth()),
				static_cast<int>(viewport.GetHeight()));
		}

		static inline void SetClearColor(const glm::vec4 &color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		static inline void Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		static inline void DrawIndexed(size_t indexCount, PrimitiveType primitiveType, IndexFormat indexFormat)
		{
			glDrawElements(
				OpenGLPrimitiveType::GetPrimitiveType(primitiveType),
				static_cast<int>(indexCount),
				OpenGLIndexFormat::GetIndexFormat(indexFormat),
				nullptr);
		}
	};
}
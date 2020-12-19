#pragma once

#include "glad/glad.h"

#include "Hazel/Core/Geometry/Rectangle.h"
#include "OpenGLPrimitiveTopology.h"
#include "OpenGLIndexFormat.h"

namespace Hazel
{
	class OpenGLDrawer
	{
	private:
		int indexFormat = GL_UNSIGNED_INT;
		int primitiveTopology = GL_TRIANGLES;

	public:
		void SetIndexFormat(IndexFormat indexFormat)
		{
			this->indexFormat = OpenGLIndexFormat::GetIndexFormat(indexFormat);
		}

		void SetPrimitiveTopology(PrimitiveTopology primitiveTopology)
		{
			this->primitiveTopology = OpenGLPrimitiveTopology::GetPrimitiveTopology(primitiveTopology);
		}

		void SetViewport(const Rectangle &viewport)
		{
			glViewport(
				static_cast<int>(viewport.Left),
				static_cast<int>(viewport.Bottom),
				static_cast<int>(viewport.GetWidth()),
				static_cast<int>(viewport.GetHeight()));
		}

		void SetClearColor(const glm::vec4 &color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		void Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void DrawIndexed(size_t indexCount)
		{
			glDrawElements(
				primitiveTopology,
				static_cast<int>(indexCount),
				indexFormat,
				nullptr);
		}
	};
}
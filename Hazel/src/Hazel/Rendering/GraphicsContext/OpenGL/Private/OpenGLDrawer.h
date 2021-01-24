#pragma once

#include "glad/glad.h"

#include "Hazel/Core/Geometry/Rectangle.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "OpenGLPrimitiveTopology.h"
#include "OpenGLIndexFormat.h"

namespace Hazel
{
	class OpenGLDrawer
	{
	public:
		static void SetViewport(const Rectangle &viewport)
		{
			glViewport(
				static_cast<int>(viewport.Left),
				static_cast<int>(viewport.Bottom),
				static_cast<int>(viewport.GetWidth()),
				static_cast<int>(viewport.GetHeight()));
		}

		static void SetClearColor(const glm::vec4 &color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		static void Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		static void DrawIndexed(const DrawCommand &command)
		{
			glDrawElements(
				OpenGLPrimitiveTopology::GetPrimitiveTopology(command.PrimitiveTopology),
				static_cast<int>(command.IndexCount),
				OpenGLIndexFormat::GetIndexFormat(command.IndexFormat),
				nullptr);
		}
	};
}
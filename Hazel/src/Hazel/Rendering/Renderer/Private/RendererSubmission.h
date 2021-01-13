#pragma once

#include "RendererContext.h"
#include "Hazel/Rendering/Renderer/RenderCommand.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class RendererSubmission
	{
	public:
		static void Submit(RendererContext &context, const RenderCommand &command)
		{
			HZ_ASSERT(command.Mesh && command.Material, "Invalid command");
			if (!context.Shader.HasShader(command.Material->Shader.get()))
			{
				context.Shader.SetShader(command.Material->Shader.get());
			}
		}
	};
}
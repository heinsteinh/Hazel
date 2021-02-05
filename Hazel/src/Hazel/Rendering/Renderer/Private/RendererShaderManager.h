#pragma once

#include "RendererContext.h"

namespace Hazel
{
	class RendererShaderManager
	{
	public:
		static void UpdateCamera(RendererContext &context, const Camera &camera)
		{
			context.Camera = &camera;
			auto shader = context.Command.Shader.lock();
			if (shader)
			{
				UploadViewProjection(context, shader);
			}
		}

		static bool HasShader(RendererContext &context, const std::shared_ptr<Shader> &shader)
		{
			return context.Command.Shader.lock() == shader;
		}

		static void SetShader(RendererContext &context, const std::shared_ptr<Shader> &shader)
		{
			context.Command.Shader = shader;
			context.Batch.SetVertexLayout(shader->GetInputLayout());
			UploadViewProjection(context, shader);
		}

	private:
		static void UploadViewProjection(RendererContext &context, const std::shared_ptr<Shader> &shader)
		{
			auto index = shader->GetProperties().ViewProjectionIndex;
			if (index)
			{
				shader->UpdateUniform().GetAttribute<glm::mat4>(*index) = context.Camera
					? context.Camera->GetViewProjection()
					: glm::mat4(1.0f);
			}
		}
	};
}
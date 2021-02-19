#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "RendererContext.h"

namespace Hazel
{
	class RendererShader
	{
	public:
		static void UpdateCamera(RendererContext &context, const Camera &camera)
		{
			context.CameraProjectionType = ProjectionType::Orthographic;
			context.ViewProjection = camera.GetViewProjection();
			context.CameraPosition = camera.GetPosition();
			UploadViewProjection(context, context.Command.Shader.lock());
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
			if (shader)
			{
				auto index = shader->GetProperties().ViewProjectionIndex;
				if (index)
				{
					shader->UpdateUniform().GetAttribute<glm::mat4>(*index) = context.ViewProjection;
				}
			}
		}
	};
}
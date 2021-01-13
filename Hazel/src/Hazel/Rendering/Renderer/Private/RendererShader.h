#pragma once

#include "Hazel/Rendering/Materials/MaterialShader.h"
#include "Hazel/Rendering/GraphicsBuffers/UniformBuffer.h"
#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Core/Camera/Camera.h"

namespace Hazel
{
	class RendererShader
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		MaterialShader *shader = nullptr;
		std::shared_ptr<UniformBuffer> uniformBuffer;

	public:
		RendererShader(const RendererInfo &info)
			: graphicsContext(info.GraphicsContext),
			uniformBuffer(info.GraphicsContext->CreateUniformBuffer(info.UniformBufferSize))
		{
			info.GraphicsContext->SetUniformBuffer(uniformBuffer.get());
		}

		MaterialShader *GetShader() const
		{
			return shader;
		}

		void SetShader(MaterialShader *shader)
		{
			this->shader = shader;
			graphicsContext->SetShader(shader->Shader.get());
			graphicsContext->SetInputLayout(shader->InputLayout.get());
			ResizeUniformBuffer(shader->Uniform.GetSize());
		}

		void ResizeUniformBuffer(size_t size)
		{
			if (uniformBuffer->GetSize() < size)
			{
				uniformBuffer = graphicsContext->CreateUniformBuffer(size);
				graphicsContext->SetUniformBuffer(uniformBuffer.get());
			}
		}

		void BufferUniform(const Camera &camera)
		{
			if (shader)
			{
				if (shader->ViewProjectionIndex)
				{
					shader->Uniform.GetAttribute<glm::mat4>(*shader->ViewProjectionIndex) = camera.GetViewProjection();
				}
				uniformBuffer->BufferData(shader->Uniform.GetData(), shader->Uniform.GetSize());
			}
		}
	};
}
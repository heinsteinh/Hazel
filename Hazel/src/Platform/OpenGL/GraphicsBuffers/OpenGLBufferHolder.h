#pragma once

#include "Platform/OpenGL/GraphicsBuffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLUniformBuffer.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/GraphicsContext/OpenGLBinder.h"

namespace Hazel
{
	class OpenGLBufferHolder
	{
	private:
		OpenGLIndexBuffer *indexBuffer = nullptr;
		OpenGLVertexBuffer *vertexBuffer = nullptr;
		std::vector<OpenGLUniformBuffer *> uniformBuffers;
		OpenGLVertexArray *vertexArray = nullptr;

	public:
		inline OpenGLIndexBuffer *GetIndexBuffer() const
		{
			return indexBuffer;
		}

		inline void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
		{
			OpenGLBinder::Bind(this->indexBuffer, indexBuffer);
		}

		inline OpenGLVertexBuffer *GetVertexBuffer() const
		{
			return vertexBuffer;
		}

		inline void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
		{
			OpenGLBinder::Bind(this->vertexBuffer, vertexBuffer);
			if (vertexArray)
			{
				vertexArray->AddCurrentVertexBuffer();
			}
		}

		inline void InitBindingCount(size_t bindingCount)
		{
			uniformBuffers.resize(bindingCount);
		}

		inline size_t GetUniformBufferBindingCount() const
		{
			return uniformBuffers.size();
		}

		inline OpenGLUniformBuffer *GetUniformBuffer(uint32_t binding) const
		{
			HZ_ASSERT(binding < uniformBuffers.size(), "Binding out of range");
			return uniformBuffers[binding];
		}

		inline void SetConstantBuffer(const std::shared_ptr<ConstantBuffer> &constantBuffer, uint32_t binding)
		{
			HZ_ASSERT(binding < uniformBuffers.size(), "Binding out of range");
			auto &uniformBuffer = uniformBuffers[binding];
			OpenGLBinder::Bind(uniformBuffer, constantBuffer);
			if (uniformBuffer)
			{
				uniformBuffer->SetBinding(binding);
			}
		}

		inline OpenGLVertexArray *GetVertexArray() const
		{
			return vertexArray;
		}

		inline void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout)
		{
			OpenGLBinder::Bind(this->vertexArray, inputLayout);
			if (vertexBuffer)
			{
				vertexArray->AddCurrentVertexBuffer();
			}
			if (indexBuffer)
			{
				indexBuffer->Bind();
			}
		}
	};
}
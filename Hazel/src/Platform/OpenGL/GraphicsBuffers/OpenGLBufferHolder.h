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
		OpenGLIndexBuffer *GetIndexBuffer() const
		{
			return indexBuffer;
		}

		void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
		{
			OpenGLBinder::Bind(this->indexBuffer, indexBuffer);
		}

		OpenGLVertexBuffer *GetVertexBuffer() const
		{
			return vertexBuffer;
		}

		void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
		{
			OpenGLBinder::Bind(this->vertexBuffer, vertexBuffer);
			if (this->vertexBuffer && vertexArray)
			{
				vertexArray->AddCurrentVertexBuffer();
			}
		}

		size_t GetMaxUniformBufferBindingCount() const
		{
			return uniformBuffers.size();
		}

		void SetMaxUniformBufferBindingCount(size_t maxUniformBufferBindingCount)
		{
			uniformBuffers.resize(maxUniformBufferBindingCount);
		}

		OpenGLUniformBuffer *GetUniformBuffer(uint32_t binding) const
		{
			HZ_ASSERT(binding < uniformBuffers.size(), "Binding out of range");
			return uniformBuffers[binding];
		}

		void SetConstantBuffer(const std::shared_ptr<ConstantBuffer> &constantBuffer, uint32_t binding)
		{
			HZ_ASSERT(binding < uniformBuffers.size(), "Binding out of range");
			auto &uniformBuffer = uniformBuffers[binding];
			OpenGLBinder::Bind(uniformBuffer, constantBuffer);
			if (uniformBuffer)
			{
				uniformBuffer->SetBinding(binding);
			}
		}

		OpenGLVertexArray *GetVertexArray() const
		{
			return vertexArray;
		}

		void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout)
		{
			OpenGLBinder::Bind(this->vertexArray, inputLayout);
			if (this->vertexArray && vertexBuffer)
			{
				vertexArray->AddCurrentVertexBuffer();
			}
			if (this->vertexArray && indexBuffer)
			{
				indexBuffer->Bind();
			}
		}
	};
}
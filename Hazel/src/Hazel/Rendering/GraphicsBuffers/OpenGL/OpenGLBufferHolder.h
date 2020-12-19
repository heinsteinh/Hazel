#pragma once

#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLIndexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLVertexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLUniformBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLVertexArray.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBinder.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

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

		void SetIndexBuffer(IndexBuffer *indexBuffer)
		{
			OpenGLBinder::Bind(this->indexBuffer, indexBuffer);
		}

		OpenGLVertexBuffer *GetVertexBuffer() const
		{
			return vertexBuffer;
		}

		void SetVertexBuffer(VertexBuffer *vertexBuffer)
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

		OpenGLUniformBuffer *GetUniformBuffer(size_t binding) const
		{
			HZ_ASSERT(binding < uniformBuffers.size(), "Binding out of range");
			return uniformBuffers[binding];
		}

		void SetConstantBuffer(ConstantBuffer *constantBuffer, size_t binding)
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

		void SetInputLayout(InputLayout *inputLayout)
		{
			OpenGLBinder::Bind(this->vertexArray, inputLayout);
			if (vertexArray && vertexBuffer)
			{
				vertexArray->AddCurrentVertexBuffer();
			}
			if (vertexArray && indexBuffer)
			{
				indexBuffer->Bind();
			}
		}
	};
}
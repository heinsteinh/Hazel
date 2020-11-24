#pragma once

#include "Platform/OpenGL/GraphicsBuffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/GraphicsContext/OpenGLBinder.h"

namespace Hazel
{
	class OpenGLBufferHolder
	{
	private:
		OpenGLVertexBuffer *vertexBuffer = nullptr;
		OpenGLVertexArray *vertexArray = nullptr;
		OpenGLIndexBuffer *indexBuffer = nullptr;

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
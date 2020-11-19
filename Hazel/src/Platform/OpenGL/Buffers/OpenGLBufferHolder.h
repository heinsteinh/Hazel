#pragma once

#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"

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

		inline IndexFormat GetIndexFormat() const
		{
			return indexBuffer ? indexBuffer->GetIndexFormat() : IndexFormat::UInt32;
		}

		inline void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
		{
			if (indexBuffer && this->indexBuffer != indexBuffer.get())
			{
				HZ_ASSERT(typeid(*indexBuffer) == typeid(OpenGLIndexBuffer), "Not an OpenGL type.");
				this->indexBuffer = static_cast<OpenGLIndexBuffer *>(indexBuffer.get());
				this->indexBuffer->Bind();
			}
		}

		inline OpenGLVertexBuffer *GetVertexBuffer() const
		{
			return vertexBuffer;
		}

		inline void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
		{
			if (vertexBuffer && this->vertexBuffer != vertexBuffer.get())
			{
				HZ_ASSERT(typeid(*vertexBuffer) == typeid(OpenGLVertexBuffer), "Not an OpenGL type.");
				this->vertexBuffer = static_cast<OpenGLVertexBuffer *>(vertexBuffer.get());
				this->vertexBuffer->Bind();
				if (vertexArray)
				{
					vertexArray->AddBoundVertexBuffer();
				}
			}
		}

		inline OpenGLVertexArray *GetVertexArray() const
		{
			return vertexArray;
		}

		inline void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout)
		{
			if (inputLayout && vertexArray != inputLayout.get())
			{
				HZ_ASSERT(typeid(*inputLayout) == typeid(OpenGLVertexArray), "Not an OpenGL type.");
				vertexArray = static_cast<OpenGLVertexArray *>(inputLayout.get());
				vertexArray->Bind();
				if (vertexBuffer)
				{
					vertexArray->AddBoundVertexBuffer();
				}
				if (indexBuffer)
				{
					indexBuffer->Bind();
				}
			}
		}
	};
}
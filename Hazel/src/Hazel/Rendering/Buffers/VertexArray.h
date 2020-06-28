#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Hazel
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual const std::vector<SharedPtr<VertexBuffer>> &GetVertexBuffers() const = 0;
		virtual const SharedPtr<IndexBuffer> &GetIndexBuffer() const = 0;
		virtual void AddVertexBuffer(const SharedPtr<VertexBuffer> &buffer) = 0;
		virtual void SetIndexBuffer(const SharedPtr<IndexBuffer> &buffer) = 0;
	};
}
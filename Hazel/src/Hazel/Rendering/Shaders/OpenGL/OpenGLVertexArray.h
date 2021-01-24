#pragma once

#include <memory>

#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLVertexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLIndexBuffer.h"

namespace Hazel
{
	class OpenGLVertexArray
	{
	private:
		uint32_t id;
		std::weak_ptr<OpenGLIndexBuffer> indexBuffer;
		std::weak_ptr<OpenGLVertexBuffer> vertexBuffer;

	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() const;
		void Unbind() const;
		std::shared_ptr<OpenGLIndexBuffer> GetIndexBuffer() const;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer);
		std::shared_ptr<OpenGLVertexBuffer> GetVertexBuffer() const;
		void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer, const VertexLayout &layout);

		uint32_t GetId() const
		{
			return id;
		}

	private:
		void AddVertexAttributes(const VertexLayout &layout);
		void AddVertexAttribute(int index, int stride, const VertexAttribute &attribute);
	};
}
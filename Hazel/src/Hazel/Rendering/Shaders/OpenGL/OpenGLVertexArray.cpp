#include "OpenGLVertexArray.h"

#include "glad/glad.h"

#include "Hazel/Core/Logging/Log.h"

#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBinder.h"
#include "Private/OpenGLDataType.h"

namespace Hazel
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &id);
		Log::Debug("Vertex array created with id {}.", id);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &id);
		Log::Debug("Vertex array with id {} destroyed.", id);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(id);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	std::shared_ptr<OpenGLIndexBuffer> OpenGLVertexArray::GetIndexBuffer() const
	{
		return indexBuffer.lock();
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
	{
		OpenGLBinder::Bind(this->indexBuffer, indexBuffer);
	}

	std::shared_ptr<OpenGLVertexBuffer> OpenGLVertexArray::GetVertexBuffer() const
	{
		return vertexBuffer.lock();
	}

	void OpenGLVertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer, const VertexLayout &layout)
	{
		if (OpenGLBinder::Bind(this->vertexBuffer, vertexBuffer))
		{
			AddVertexAttributes(layout);
		}
	}

	void OpenGLVertexArray::AddVertexAttributes(const VertexLayout &layout)
	{
		for (size_t i = 0; i < layout.GetAttributeCount(); i++)
		{
			AddVertexAttribute(
				static_cast<int>(i),
				static_cast<int>(layout.GetStride()),
				layout.GetAttribute(i));
		}
	}

	void OpenGLVertexArray::AddVertexAttribute(int index, int stride, const VertexAttribute &attribute)
	{
		glEnableVertexArrayAttrib(id, index);
		glVertexAttribPointer(
			index,
			static_cast<int>(attribute.GetComponentCount()),
			OpenGLDataType::GetDataType(attribute.GetComponentType()),
			attribute.IsNormalized() ? GL_TRUE : GL_FALSE,
			stride,
			reinterpret_cast<const void *>(attribute.GetOffset()));
	}
}
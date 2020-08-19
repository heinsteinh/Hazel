#include "OpenGLVertexArray.h"

#include "glad/glad.h"

#include "OpenGLDataType.h"

namespace Hazel
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &id);
		Log::Info("Vertex array created with id {}.", id);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &id);
		Log::Info("Vertex array with id {} destroyed.", id);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(id);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	const std::vector<std::shared_ptr<VertexBuffer>> &OpenGLVertexArray::GetVertexBuffers() const
	{
		return vertexBuffers;
	}

	const std::shared_ptr<IndexBuffer> &OpenGLVertexArray::GetIndexBuffer() const
	{
		return indexBuffer;
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &buffer)
	{
		vertexBuffers.push_back(buffer);
		Bind();
		buffer->Bind();
		SetupVerticesAttributes(buffer->GetLayout());
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &buffer)
	{
		indexBuffer = buffer;
	}

	void OpenGLVertexArray::SetupVerticesAttributes(const BufferLayout &layout)
	{
		for (size_t i = 0; i < layout.GetSize(); i++)
		{
			SetupVertexAttributes(i, layout);
		}
	}

	void OpenGLVertexArray::SetupVertexAttributes(size_t index, const BufferLayout &layout)
	{
		glEnableVertexAttribArray(static_cast<int>(index));
		const auto &element = layout.GetElement(index);
		glVertexAttribPointer(
			static_cast<int>(index),
			static_cast<int>(element.GetComponentCount()),
			OpenGLDataType::FromDataType(element.GetComponentType()),
			element.IsNormalized() ? GL_TRUE : GL_FALSE,
			static_cast<int>(layout.GetStride()),
			reinterpret_cast<const void *>(element.GetOffset()));
	}
}
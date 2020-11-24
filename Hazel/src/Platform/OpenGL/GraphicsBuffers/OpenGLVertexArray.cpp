#include "OpenGLVertexArray.h"

#include "glad/glad.h"

#include "OpenGLDataType.h"

namespace Hazel
{
	OpenGLVertexArray::OpenGLVertexArray(const VertexAttributes &vertexAttributes)
		: InputLayout(vertexAttributes)
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

	void OpenGLVertexArray::AddCurrentVertexBuffer()
	{
		auto &vertexAttributes = GetAttributes();
		for (size_t i = 0; i < vertexAttributes.GetSize(); i++)
		{
			int index = static_cast<int>(i);
			auto &attribute = vertexAttributes.GetAttribute(i);
			glEnableVertexArrayAttrib(id, index);
			glVertexAttribPointer(
				index,
				static_cast<int>(attribute.GetComponentCount()),
				OpenGLDataType::GetDataType(attribute.GetComponentType()),
				attribute.IsNormalized() ? GL_TRUE : GL_FALSE,
				static_cast<int>(vertexAttributes.GetStride()),
				reinterpret_cast<const void *>(attribute.GetOffset()));
		}
	}
}
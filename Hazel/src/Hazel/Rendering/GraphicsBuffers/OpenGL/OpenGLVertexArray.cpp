#include "OpenGLVertexArray.h"

#include "glad/glad.h"

#include "Hazel/Core/Logging/Log.h"

#include "OpenGLDataType.h"

namespace Hazel
{
	OpenGLVertexArray::OpenGLVertexArray(const VertexLayout &vertexAttributes)
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
		auto &layout = GetVertexLayout();
		for (size_t i = 0; i < layout.GetAttributeCount(); i++)
		{
			int index = static_cast<int>(i);
			auto &attribute = layout.GetAttribute(i);
			glEnableVertexArrayAttrib(id, index);
			glVertexAttribPointer(
				index,
				static_cast<int>(attribute.GetComponentCount()),
				OpenGLDataType::GetDataType(attribute.GetComponentType()),
				attribute.IsNormalized() ? GL_TRUE : GL_FALSE,
				static_cast<int>(layout.GetStride()),
				reinterpret_cast<const void *>(attribute.GetOffset()));
		}
	}
}
#pragma once

namespace Hazel
{
	class OpenGLUniformBuffer
	{
	private:
		size_t size = 0;
		uint32_t id = 0;

	public:
		OpenGLUniformBuffer(size_t size);
		~OpenGLUniformBuffer();

		void SetBinding(size_t binding);
		void Bind() const;
		void Unbind() const;
		void BufferData(const void *data, size_t size);

		size_t GetSize() const
		{
			return size;
		}

		uint32_t GetId() const
		{
			return id;
		}
	};
}
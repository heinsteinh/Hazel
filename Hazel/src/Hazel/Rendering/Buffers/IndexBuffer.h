#pragma once

namespace Hazel
{
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual size_t GetSize() const = 0;
		virtual void SetData(const void *data, size_t size) = 0;
	};
}
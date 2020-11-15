#pragma once

namespace Hazel
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual size_t GetSize() const = 0;
		virtual void BufferData(const void *data, size_t size) = 0;
	};
}
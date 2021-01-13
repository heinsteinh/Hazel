#pragma once

namespace Hazel
{
	class VertexBuffer
	{
	private:
		size_t size = 0;

	public:
		VertexBuffer(size_t size)
			: size(size)
		{
		}

		virtual ~VertexBuffer() = default;

		virtual void BufferData(const void *data, size_t size) = 0;

		size_t GetSize() const
		{
			return size;
		}
	};
}
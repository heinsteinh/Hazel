#pragma once

namespace Hazel
{
	class IndexBuffer
	{
	private:
		size_t size = 0;

	public:
		constexpr IndexBuffer(size_t size)
			: size(size)
		{
		}

		virtual ~IndexBuffer() = default;

		virtual void BufferData(const void *data, size_t size) = 0;

		constexpr size_t GetSize() const
		{
			return size;
		}
	};
}
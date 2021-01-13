#pragma once

namespace Hazel
{
	class UniformBuffer
	{
	private:
		size_t size = 0;

	public:
		UniformBuffer(size_t size)
			: size(size)
		{
		}

		virtual ~UniformBuffer() = default;

		virtual void BufferData(const void *data, size_t size) = 0;

		size_t GetSize() const
		{
			return size;
		}
	};
}
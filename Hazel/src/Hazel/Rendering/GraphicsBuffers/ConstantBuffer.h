#pragma once

namespace Hazel
{
	class ConstantBuffer
	{
	private:
		size_t size = 0;

	public:
		constexpr ConstantBuffer(size_t size)
			: size(size)
		{
		}

		virtual ~ConstantBuffer() = default;

		virtual void BufferData(const void *data, size_t size) = 0;

		constexpr size_t GetSize() const
		{
			return size;
		}
	};
}
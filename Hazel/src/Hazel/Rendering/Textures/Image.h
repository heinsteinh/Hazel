#pragma once

#include "ColorFormat.h"

namespace Hazel
{
	class Image
	{
	private:
		size_t width = 0;
		size_t height = 0;
		ColorFormat format;
		void *data = nullptr;

	public:
		Image() = default;
		Image(const std::string &filename, bool flipVertically = true);
		Image(const Image &other) = delete;
		Image(Image &&other) noexcept;
		~Image();

		void *ReleaseData();

		Image &operator=(const Image &other) = delete;
		Image &operator=(Image &&other) noexcept;

		constexpr size_t GetWidth() const
		{
			return width;
		}

		constexpr size_t GetHeight() const
		{
			return height;
		}

		constexpr ColorFormat GetFormat() const
		{
			return format;
		}

		constexpr void *GetData() const
		{
			return data;
		}
	};
}
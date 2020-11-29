#pragma once

#include "Hazel/FileSystem/OpenFileException.h"

namespace Hazel
{
	class Image
	{
	private:
		glm::vec2 size{0.0f};
		int channelCount = 0;
		void *data = nullptr;

	public:
		Image() = default;
		Image(const std::string &filename, bool flipVertically = true);
		Image(const Image &other) = delete;
		Image(Image &&other) noexcept;
		~Image();

		Image &operator=(const Image &other) = delete;
		Image &operator=(Image &&other) noexcept;

		constexpr glm::vec2 GetSize() const
		{
			return size;
		}

		constexpr float GetWidth() const
		{
			return size.x;
		}

		constexpr float GetHeight() const
		{
			return size.y;
		}

		constexpr int GetChannelCount() const
		{
			return channelCount;
		}

		constexpr void *GetData() const
		{
			return data;
		}
	};
}
#pragma once

namespace Hazel
{
	class Image
	{
	private:
		float width = 0.0f;
		float height = 0.0f;
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

		constexpr float GetWidth() const
		{
			return width;
		}

		constexpr float GetHeight() const
		{
			return height;
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
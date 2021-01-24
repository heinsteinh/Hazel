#include "Image.h"

#include "stb_image.h"

namespace Hazel
{
	Image Image::FromFile(const std::string &filename, bool flipVertically)
	{
		Image image;
		stbi_set_flip_vertically_on_load(flipVertically ? 1 : 0);
		int width = 0;
		int height = 0;
		image.data = stbi_load(filename.c_str(), &width, &height, &image.channelCount, 0);
		if (!image.data)
		{
			throw OpenFileException(filename);
		}
		image.size = {static_cast<float>(width), static_cast<float>(height)};
		return image;
	}

	Image::Image(Image &&other) noexcept
		: size(other.size),
		channelCount(other.channelCount),
		data(std::exchange(other.data, nullptr))
	{
	}

	Image::~Image()
	{
		if (data)
		{
			stbi_image_free(data);
		}
	}

	Image &Image::operator=(Image &&other) noexcept
	{
		std::swap(size, other.size);
		std::swap(channelCount, other.channelCount);
		std::swap(data, other.data);
		return *this;
	}
}
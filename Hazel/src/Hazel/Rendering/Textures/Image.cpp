#include "Image.h"

#include "stb_image.h"

#include "ColorFormatInfo.h"

namespace Hazel
{
	Image::Image(const std::string &filename, bool flipVertically)
	{
		stbi_set_flip_vertically_on_load(flipVertically ? 1 : 0);
		int width = 0;
		int height = 0;
		int numChannels = 0;
		data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
		this->width = width;
		this->height = height;
		format = ColorFormatInfo::FromNumChannels(numChannels);
	}

	Image::Image(Image &&other) noexcept
		: width(other.width),
		height(other.height),
		format(other.format),
		data(other.ReleaseData())
	{
	}

	Image::~Image()
	{
		if (data)
		{
			stbi_image_free(data);
		}
	}

	void *Image::ReleaseData()
	{
		width = height = 0;
		void *temp = data;
		data = nullptr;
		return temp;
	}

	Image &Image::operator=(Image &&other) noexcept
	{
		width = other.width;
		height = other.height;
		format = other.format;
		data = other.ReleaseData();
		return *this;
	}
}
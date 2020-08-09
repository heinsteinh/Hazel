#include "Image.h"

#include "stb_image.h"

#include "ColorFormatHelper.h"

namespace Hazel
{
	Image::Image(const std::string &filename, bool flipVertically)
	{
		stbi_set_flip_vertically_on_load(flipVertically ? 1 : 0);
		int width = 0;
		int height = 0;
		int numChannels = 0;
		data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
		this->width = static_cast<float>(width);
		this->height = static_cast<float>(height);
		format = ColorFormatHelper::CreateFromNumChannels(numChannels);
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
		return std::exchange(data, nullptr);
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
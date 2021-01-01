#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Core/Geometry/Size.h"

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

		glm::vec2 GetSize() const
		{
			return size;
		}

		float GetWidth() const
		{
			return size.x;
		}

		float GetHeight() const
		{
			return size.y;
		}

		int GetChannelCount() const
		{
			return channelCount;
		}

		void *GetData() const
		{
			return data;
		}

		bool IsEmpty() const
		{
			return Size::IsEmpty(size);
		}
	};
}
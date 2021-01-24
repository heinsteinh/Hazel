#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Core/Geometry/Size.h"
#include "Hazel/Core/FileSystem/OpenFileException.h"

namespace Hazel
{
	class Image
	{
	private:
		glm::vec2 size{0.0f};
		int channelCount = 0;
		void *data = nullptr;

	public:
		static Image FromFile(const std::string &filename, bool flipVertically = true);

		Image() = default;
		Image(const Image &other) = delete;
		Image(Image &&other) noexcept;
		~Image();

		Image &operator=(const Image &other) = delete;
		Image &operator=(Image &&other) noexcept;

		const glm::vec2 &GetSize() const
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
#pragma once

#include "TextureInfo.h"
#include "Hazel/Core/Geometry/Size.h"

namespace Hazel
{
	class Texture
	{
	private:
		TextureInfo info;

	public:
		Texture(const TextureInfo &info)
			: info(info)
		{
		}

		virtual ~Texture() = default;

		virtual void BufferData(const void *data) = 0;
		virtual void *GetHandle() const = 0;

		constexpr const TextureInfo &GetInfo() const
		{
			return info;
		}

		constexpr TextureFormat GetFormat() const
		{
			return info.Format;
		}

		constexpr const glm::vec2 &GetSize() const
		{
			return info.Size;
		}

		constexpr float GetWidth() const
		{
			return info.Size.x;
		}

		constexpr float GetHeight() const
		{
			return info.Size.y;
		}

		constexpr float GetAspectRatio() const
		{
			return Size::GetAspectRatio(info.Size);
		}
	};
}
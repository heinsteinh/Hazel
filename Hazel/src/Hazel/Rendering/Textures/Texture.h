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

		const TextureInfo &GetInfo() const
		{
			return info;
		}

		TextureFormat GetFormat() const
		{
			return info.Format;
		}

		bool IsEmpty() const
		{
			return Size::IsEmpty(info.Size);
		}

		const glm::vec2 &GetSize() const
		{
			return info.Size;
		}

		float GetWidth() const
		{
			return info.Size.x;
		}

		float GetHeight() const
		{
			return info.Size.y;
		}

		float GetAspectRatio() const
		{
			return Size::GetAspectRatio(info.Size);
		}
	};
}
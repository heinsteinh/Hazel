#pragma once

#include "Hazel/Core/Geometry/Size.h"
#include "TextureInfo.h"

namespace Hazel
{
	class Texture
	{
	private:
		void *handle = nullptr;
		TextureInfo info;

	public:
		Texture(void *handle, const TextureInfo &info)
			: handle(handle),
			info(info)
		{
		}

		virtual ~Texture() = default;

		virtual void BufferData(const void *data) = 0;

		void *GetHandle() const
		{
			return handle;
		}

		const TextureInfo &GetInfo() const
		{
			return info;
		}

		const std::string &GetName() const
		{
			return info.Name;
		}

		const std::string &GetFilename() const
		{
			return info.Filename;
		}

		const glm::vec2 &GetSize() const
		{
			return info.Size;
		}

		bool IsEmpty() const
		{
			return Size::IsEmpty(info.Size);
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

		TextureFormat GetFormat() const
		{
			return info.Format;
		}
	};
}
#pragma once

#include "FramebufferInfo.h"
#include "FramebufferAttachmentType.h"
#include "FramebufferCreationException.h"
#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class Framebuffer
	{
	private:
		FramebufferInfo info;

	public:
		Framebuffer(const FramebufferInfo &info)
			: info(info)
		{
		}

		virtual ~Framebuffer() = default;

		virtual std::shared_ptr<Texture> GetColorAttachment() const = 0;
		virtual std::shared_ptr<Texture> GetDepthAttachment() const = 0;

		constexpr const FramebufferInfo &GetInfo() const
		{
			return info;
		}

		constexpr Size GetSize() const
		{
			return GetInfo().Size;
		}

		constexpr float GetWidth() const
		{
			return GetSize().Width;
		}

		constexpr float GetHeight() const
		{
			return GetSize().Height;
		}

		constexpr float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}
	};
}
#pragma once

#include "FramebufferInfo.h"
#include "FramebufferAttachmentType.h"
#include "FramebufferCreationException.h"
#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class Framebuffer
	{
	public:
		virtual ~Framebuffer() = default;

		virtual const FramebufferInfo &GetInfo() const = 0;
		virtual std::shared_ptr<Texture> GetColorAttachement() const = 0;
		virtual std::shared_ptr<Texture> GetDepthAttachement() const = 0;

		inline Size GetSize() const
		{
			return GetInfo().Size;
		}

		inline float GetWidth() const
		{
			return GetSize().Width;
		}

		inline float GetHeight() const
		{
			return GetSize().Height;
		}

		inline float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}
	};
}
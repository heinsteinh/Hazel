#pragma once

#include "FramebufferInfo.h"
#include "FramebufferCreationException.h"

namespace Hazel
{
	class Framebuffer
	{
	public:
		virtual ~Framebuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual const FramebufferInfo &GetInfo() const = 0;
		virtual void *GetColorAttachement() const = 0;

		inline Size GetSize() const
		{
			return GetInfo().Dimensions;
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
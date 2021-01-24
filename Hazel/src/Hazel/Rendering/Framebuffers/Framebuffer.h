#pragma once

#include "Hazel/Core/Geometry/Size.h"
#include "Hazel/Rendering/Textures/Texture.h"
#include "FramebufferInfo.h"
#include "FramebufferCreationException.h"

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

		virtual Texture &GetColorAttachment() const = 0;
		virtual Texture &GetDepthAttachment() const = 0;

		const FramebufferInfo &GetInfo() const
		{
			return info;
		}

		const glm::vec2 &GetSize() const
		{
			return GetInfo().Size;
		}

		float GetWidth() const
		{
			return GetSize().x;
		}

		float GetHeight() const
		{
			return GetSize().y;
		}

		float GetAspectRatio() const
		{
			return Size::GetAspectRatio(GetSize());
		}
	};
}
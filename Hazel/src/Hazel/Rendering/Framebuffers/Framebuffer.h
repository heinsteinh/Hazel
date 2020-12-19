#pragma once

#include <memory>

#include "FramebufferInfo.h"
#include "FramebufferAttachmentType.h"
#include "FramebufferCreationException.h"
#include "Hazel/Rendering/Textures/Texture.h"
#include "Hazel/Core/Geometry/Size.h"

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

		constexpr const glm::vec2 &GetSize() const
		{
			return GetInfo().Size;
		}

		constexpr float GetWidth() const
		{
			return GetSize().x;
		}

		constexpr float GetHeight() const
		{
			return GetSize().y;
		}

		constexpr float GetAspectRatio() const
		{
			return Size::GetAspectRatio(GetSize());
		}
	};
}
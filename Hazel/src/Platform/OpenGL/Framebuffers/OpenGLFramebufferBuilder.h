#pragma once

#include "OpenGLFramebufferHolder.h"
#include "Hazel/Framebuffers/FramebufferCreationException.h"

namespace Hazel
{
	class OpenGLFramebufferBuilder
	{
	public:
		static inline OpenGLFramebufferHolder Build(const FramebufferInfo &info)
		{
			OpenGLFramebufferHolder holder(info);
			if (!holder.IsComplete())
			{
				throw FramebufferCreationException(fmt::format("Framebuffer creation failed with status {}.",
					holder.GetStatusName()));
			}
			return holder;
		}

		OpenGLFramebufferBuilder() = delete;
	};
}
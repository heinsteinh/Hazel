#pragma once

#include "Hazel/Core/Utils/StaticCast.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBindingContext.h"

namespace Hazel
{
	class OpenGLTextureBinder
	{
	public:
		static void BindTextures(OpenGLBindingContext &context, const std::vector<std::weak_ptr<Texture>> &textures)
		{
			for (size_t slot = 0; slot < textures.size(); slot++)
			{
				auto texture = StaticCast::Convert<OpenGLTexture>(textures[slot].lock());
				if (texture)
				{
					texture->SetSlot(static_cast<uint32_t>(slot));
				}
				context.SetTexture(texture, slot);
			}
		}
	};
}
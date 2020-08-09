#pragma once

#include "Hazel/Rendering/RenderApi/RenderApiInfo.h"

namespace Hazel
{
	class OpenGLInfo : public RenderApiInfo
	{
	public:
		virtual size_t GetMaxTextures() const override;
	};
}
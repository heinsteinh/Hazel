#pragma once

#include "Hazel/RenderApi/RenderApiInfo.h"

namespace Hazel
{
	class OpenGLInfo : public RenderApiInfo
	{
	public:
		virtual size_t GetMaxTextures() const override;
	};
}
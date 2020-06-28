#pragma once

#include "Hazel/Rendering/Core/RenderApiInfo.h"

namespace Hazel
{
	class OpenGLInfo : public RenderApiInfo
	{
	public:
		virtual size_t GetMaxTextureUnits() const override;
	};
}
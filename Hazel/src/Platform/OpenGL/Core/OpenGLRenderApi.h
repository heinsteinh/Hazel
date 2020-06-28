#pragma once

#include "Hazel/Rendering/Core/RenderApi.h"
#include "OpenGLFactory.h"
#include "OpenGLDrawer.h"

namespace Hazel
{
	class OpenGLRenderApi : public RenderApi
	{
	private:
		OpenGLFactory factory;
		OpenGLDrawer drawer;

	public:
		inline virtual RenderApiFactory &GetFactory() override
		{
			return factory;
		}

		inline virtual Drawer &GetDrawer() override
		{
			return drawer;
		}
	};
}
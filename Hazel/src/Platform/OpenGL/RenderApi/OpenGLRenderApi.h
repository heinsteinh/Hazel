#pragma once

#include "Hazel/RenderApi/RenderApi.h"
#include "OpenGLInfo.h"
#include "OpenGLFactory.h"
#include "OpenGLDrawer.h"

namespace Hazel
{
	class OpenGLRenderApi : public RenderApi
	{
	private:
		OpenGLInfo info;
		OpenGLFactory factory;
		OpenGLDrawer drawer;

	public:
		inline virtual RenderApiInfo &GetInfo() override
		{
			return info;
		}

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
#pragma once

#include "RenderApiInfo.h"
#include "RenderApiFactory.h"
#include "Drawer.h"

namespace Hazel
{
	class RenderApi
	{
	public:
		virtual ~RenderApi() = default;

		virtual RenderApiInfo &GetInfo() = 0;
		virtual RenderApiFactory &GetFactory() = 0;
		virtual Drawer &GetDrawer() = 0;
	};
}
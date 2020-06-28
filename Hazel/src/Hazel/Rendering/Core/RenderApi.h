#pragma once

#include "RenderApiFactory.h"
#include "Drawer.h"

namespace Hazel
{
	class RenderApi
	{
	public:
		virtual ~RenderApi() = default;

		virtual RenderApiFactory &GetFactory() = 0;
		virtual Drawer &GetDrawer() = 0;
	};
}
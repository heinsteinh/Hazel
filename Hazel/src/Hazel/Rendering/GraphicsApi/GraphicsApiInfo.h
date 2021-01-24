#pragma once

#include <string>

namespace Hazel
{
	struct GraphicsApiInfo
	{
		std::string Version;
		std::string Vendor;
		std::string Renderer;
		size_t TextureSlotCount = 0;
		size_t UniformBindingCount = 0;
	};
}
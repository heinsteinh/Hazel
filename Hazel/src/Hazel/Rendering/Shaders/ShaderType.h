#pragma once

namespace Hazel
{
	enum class ShaderType
	{
		Unknown = -1,
		Vertex,
		Pixel,
		Fragment = Pixel,
		Count = Pixel + 1
	};
}
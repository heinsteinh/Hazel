#pragma once

namespace Hazel
{
	enum class ShaderType
	{
		Unknown = -1,
		Vertex,
		Fragment,
		Count = Fragment + 1
	};
}
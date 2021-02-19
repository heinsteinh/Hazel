#pragma once

namespace Hazel
{
	enum class ShaderDataType
	{
		Unknown = -1,
		Float,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4,
		Int,
		Int2,
		Int3,
		Int4,
		Bool,
		Count = Bool + 1
	};
}
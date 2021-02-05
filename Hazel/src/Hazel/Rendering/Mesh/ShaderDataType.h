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
		Matrix3,
		Matrix4,
		Integer,
		Integer2,
		Integer3,
		Integer4,
		Bool,
		Count = Bool + 1
	};
}
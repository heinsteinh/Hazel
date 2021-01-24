#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Mesh/IndexFormat.h"

namespace Hazel
{
	class OpenGLIndexFormat
	{
	public:
		static constexpr int GetIndexFormat(IndexFormat format)
		{
			switch (format)
			{
			case IndexFormat::UInt8:
				return GL_UNSIGNED_BYTE;
			case IndexFormat::UInt16:
				return GL_UNSIGNED_SHORT;
			case IndexFormat::UInt32:
				return GL_UNSIGNED_INT;
			}
			return GL_UNSIGNED_INT;
		}
	};
}
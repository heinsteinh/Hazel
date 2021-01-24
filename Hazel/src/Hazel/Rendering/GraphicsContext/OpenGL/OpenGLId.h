#pragma once

#include <cstdint>

namespace Hazel
{
	class OpenGLId
	{
	public:
		static void *GetHandle(uint32_t id)
		{
			return reinterpret_cast<void *>(static_cast<size_t>(id));
		}
	};
}
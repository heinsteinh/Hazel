#pragma once

namespace Hazel
{
	class RenderApiInfo
	{
	public:
		virtual ~RenderApiInfo() = default;

		virtual size_t GetMaxTextures() const = 0;
	};
}
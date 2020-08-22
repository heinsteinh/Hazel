#pragma once

namespace Hazel
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual float GetWidth() const = 0;
		virtual void SetData(const void *data) = 0;
		virtual void Bind(uint32_t slot = 0) const = 0;
	};
}
#pragma once

namespace Hazel
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual size_t GetWidth() const = 0;
		virtual void SetData(const void *data) = 0;
		virtual void Bind(size_t slot = 0) const = 0;
	};
}
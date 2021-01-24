#pragma once

#include <optional>

namespace Hazel
{
	struct ShaderInputMap
	{
		std::optional<size_t> PositionIndex;
		std::optional<size_t> ColorIndex;
		std::optional<size_t> TextureCoordinatesIndex;
		std::optional<size_t> TextureSlotIndex;
	};
}
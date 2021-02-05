#pragma once

#include <optional>

namespace Hazel
{
	struct ShaderProperties
	{
		std::optional<size_t> ViewProjectionIndex;
		std::optional<size_t> PositionIndex;
		std::optional<size_t> ColorIndex;
		std::optional<size_t> TextureCoordinatesIndex;
		std::optional<size_t> TextureSlotIndex;
	};
}
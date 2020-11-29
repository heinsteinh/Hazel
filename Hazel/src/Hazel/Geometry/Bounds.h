#pragma once

#include "Clamper.h"

namespace Hazel
{
	struct Bounds
	{
		std::optional<float> MinX;
		std::optional<float> MaxX;
		std::optional<float> MinY;
		std::optional<float> MaxY;
		std::optional<float> MinZ;
		std::optional<float> MaxZ;

		constexpr bool ContainsX(float position) const
		{
			return (!MinX || position >= MinX) && (!MaxX || position <= MaxX);
		}

		constexpr bool ContainsY(float position) const
		{
			return (!MinY || position >= MinY) && (!MaxY || position <= MaxY);
		}

		constexpr bool ContainsZ(float position) const
		{
			return (!MinZ || position >= MinZ) && (!MaxZ || position <= MaxZ);
		}

		constexpr bool Contains(const glm::vec2 &position) const
		{
			return ContainsX(position.x) && ContainsY(position.y);
		}

		constexpr bool Contains(const glm::vec3 &position) const
		{
			return ContainsX(position.x) && ContainsY(position.y) && ContainsZ(position.z);
		}

		constexpr float ClampX(float position) const
		{
			return Clamper::Clamp(position, MinX, MaxX);
		}

		constexpr float ClampY(float position) const
		{
			return Clamper::Clamp(position, MinY, MaxY);
		}

		constexpr float ClampZ(float position) const
		{
			return Clamper::Clamp(position, MinZ, MaxZ);
		}

		constexpr glm::vec2 Clamp(const glm::vec2 &position) const
		{
			return {ClampX(position.x), ClampY(position.y)};
		}

		constexpr glm::vec3 Clamp(const glm::vec3 &position) const
		{
			return {ClampX(position.x), ClampY(position.y), ClampZ(position.z)};
		}
	};
}
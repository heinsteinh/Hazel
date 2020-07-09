#pragma once

#include "DrawData.h"

namespace Hazel
{
	class RectangleDrawData
	{
	private:
		static inline std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};

		static inline std::vector<glm::vec4> positions = {
			{-0.5f, 0.5f, 0.0f, 1.0f},
			{0.5f, 0.5f, 0.0f, 1.0f},
			{0.5f, -0.5f, 0.0f, 1.0f},
			{-0.5f, -0.5f, 0.0f, 1.0f}
		};

		static inline std::vector<glm::vec2> textureCoordinates = {
			{0.0f, 1.0f},
			{1.0f, 1.0f},
			{1.0f, 0.0f},
			{0.0f, 0.0f}
		};

		static inline DrawData drawData = {
			indices,
			{{positions[0], textureCoordinates[0]},
			{positions[1], textureCoordinates[1]},
			{positions[2], textureCoordinates[2]},
			{positions[3], textureCoordinates[3]}}
		};

	public:
		static constexpr const DrawData &Get()
		{
			return drawData;
		}

		RectangleDrawData() = delete;
	};
}
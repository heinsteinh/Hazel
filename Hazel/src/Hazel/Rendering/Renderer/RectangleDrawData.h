#pragma once

#include "DrawData.h"

namespace Hazel
{
	class RectangleDrawData
	{
	private:
		static inline std::vector<unsigned int> indexes = {0, 1, 2, 2, 3, 0};

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
			indexes,
			{{positions[0], textureCoordinates[0]},
			{positions[1], textureCoordinates[1]},
			{positions[2], textureCoordinates[2]},
			{positions[3], textureCoordinates[3]}}
		};

	public:
		static inline DrawData Get(const glm::vec4 &color, const std::shared_ptr<Texture2D> &texture)
		{
			auto result = drawData;
			for (auto &mesh : result.Meshes)
			{
				mesh.Color = color;
				mesh.Texture = texture;
			}
			return result;
		}

		RectangleDrawData() = delete;
	};
}
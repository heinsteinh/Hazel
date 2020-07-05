#pragma once

#include "TemplateBatch.h"
#include "TextureBatch.h"
#include "BatchBuffer.h"
#include "DrawData.h"

namespace Hazel
{
	class Batch
	{
	private:
		TemplateBatch<unsigned int> indexes;
		TemplateBatch<Vertex> vertices;
		TextureBatch textures;
		BatchBuffer buffer;
		std::shared_ptr<Texture2D> whiteTexture;

	public:
		Batch(const BatchInfo &info);

		void Clear();
		void Add(const DrawData &drawData);
		void BufferData();
		void Bind() const;

		constexpr size_t GetIndexCount() const
		{
			return indexes.GetSize();
		}

	private:
		void AddIndexes(const DrawData &drawData);
		void AddVertices(const DrawData &drawData);
		float AddTexture(const std::shared_ptr<Texture2D> &texture);
	};
}
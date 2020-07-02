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
		std::shared_ptr<Texture2D> defaultTexture;

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
		int AddTexture(const std::shared_ptr<Texture2D> &texture);
	};
}
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

		constexpr size_t GetIndexCount() const
		{
			return indexes.GetSize();
		}

		constexpr size_t GetMaxIndexes() const
		{
			return indexes.GetMaxSize();
		}

		constexpr size_t GetMaxVertices() const
		{
			return vertices.GetMaxSize();
		}

		inline size_t GetMaxTextures() const
		{
			return textures.GetMaxSize();
		}

		void Clear();
		bool Add(const DrawData &drawData);
		void BufferData();
		void Bind() const;

	private:
		bool CanContain(const DrawData &drawData) const;
		bool TryAdd(const DrawData &drawData);
		void AddIndexes(const DrawData &drawData);
		void AddVertices(const DrawData &drawData, size_t slot);
	};
}
#pragma once

#include "BatchContainer.h"
#include "TextureBatch.h"
#include "BatchBuffer.h"
#include "DrawData.h"

namespace Hazel
{
	class Batch
	{
	private:
		BatchContainer<unsigned int> indices;
		BatchContainer<Vertex> vertices;
		TextureBatch textures;
		BatchBuffer buffer;
		std::shared_ptr<Texture2D> whiteTexture;

	public:
		Batch(const BatchInfo &info);

		constexpr size_t GetIndexCount() const
		{
			return indices.GetSize();
		}

		constexpr size_t GetMaxIndices() const
		{
			return indices.GetMaxSize();
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
		void AddIndices(const DrawData &drawData);
		void AddVertices(const DrawData &drawData, size_t slot);
	};
}
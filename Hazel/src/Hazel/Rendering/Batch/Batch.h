#pragma once

#include "Hazel/RenderApi/RenderApiFactory.h"
#include "Hazel/Rendering/DrawData.h"
#include "BatchContainer.h"
#include "TextureBatch.h"
#include "BatchBuffer.h"

namespace Hazel
{
	class Batch
	{
	private:
		BatchContainer<uint32_t> indices;
		BatchContainer<Vertex> vertices;
		TextureBatch textures;
		BatchBuffer buffer;
		std::shared_ptr<Texture> whiteTexture;

	public:
		Batch(RenderApiFactory &factory);

		void Init(const BatchInfo &info);

		constexpr size_t GetIndexCount() const
		{
			return indices.GetSize();
		}

		constexpr size_t GetMaxIndices() const
		{
			return indices.GetMaxSize();
		}

		constexpr size_t GetVertexCount() const
		{
			return vertices.GetSize();
		}

		constexpr size_t GetMaxVertices() const
		{
			return vertices.GetMaxSize();
		}

		constexpr size_t GetTextureCount() const
		{
			return textures.GetSize();
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
		void AddVertices(const DrawData &drawData, size_t textureSlot);
	};
}
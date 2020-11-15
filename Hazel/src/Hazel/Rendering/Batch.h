#pragma once

#include "DrawData.h"
#include "Vertex.h"
#include "BatchVertices.h"
#include "BatchIndices.h"
#include "BatchTextures.h"
#include "BatchBuffer.h"

namespace Hazel
{
	class Batch
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		BatchIndices indices;
		BatchVertices<Vertex> vertices;
		BatchTextures textures;
		BatchBuffer buffer;
		std::shared_ptr<Texture> whiteTexture;

	public:
		Batch(const RendererInfo &info);

		void Clear();
		bool Add(const DrawData &drawData);
		void BufferData();
		void Bind() const;

		inline size_t GetIndexCount() const
		{
			return indices.GetElementCount();
		}

		inline size_t GetMaxIndices() const
		{
			return indices.GetMaxElementCount();
		}

		inline size_t GetVertexCount() const
		{
			return vertices.GetElementCount();
		}

		inline size_t GetMaxVertices() const
		{
			return vertices.GetMaxElementCount();
		}

		inline size_t GetTextureCount() const
		{
			return textures.GetSize();
		}

		inline size_t GetMaxTextures() const
		{
			return textures.GetMaxSize();
		}

	private:
		bool CanContain(const DrawData &drawData) const;
		bool TryAdd(const DrawData &drawData);
		void AddIndices(const DrawData &drawData);
		void AddVertices(const DrawData &drawData, size_t textureSlot);
	};
}
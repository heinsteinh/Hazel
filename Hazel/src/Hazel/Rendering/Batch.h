#pragma once

#include "DrawData.h"
#include "Vertex.h"
#include "BatchIndices.h"
#include "BatchTextures.h"
#include "BatchBuffers.h"

namespace Hazel
{
	class Batch
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		BatchIndices indices;
		BatchArray<Vertex> vertices;
		BatchTextures textures;
		BatchBuffers buffers;
		std::shared_ptr<Texture> whiteTexture;

	public:
		Batch(const RendererInfo &info);

		void Clear();
		bool Add(const DrawData &drawData);
		void BufferData();
		void BindBuffers() const;
		void BindTextures() const;

		inline size_t GetIndexCount() const
		{
			return indices.GetIndexCount();
		}

		inline size_t GetMaxIndexCount() const
		{
			return indices.GetMaxIndexCount();
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
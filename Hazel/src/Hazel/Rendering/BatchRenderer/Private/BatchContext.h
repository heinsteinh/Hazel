#pragma once

#include "Hazel/Rendering/BatchRenderer/BatchInfo.h"
#include "BatchIndices.h"
#include "BatchConstants.h"
#include "BatchTextures.h"
#include "BatchBuffers.h"
#include "Hazel/Rendering/Renderer2D/DrawData.h"

namespace Hazel
{
	class BatchContext
	{
	private:
		BatchIndices indices;
		BatchArray<BatchVertex> vertices;
		BatchConstants constants;
		BatchTextures textures;
		BatchBuffers buffers;
		std::shared_ptr<Shader> shader;

	public:
		BatchContext(GraphicsContext &graphicsContext, const BatchInfo &info);

		void SetViewProjectionMatrix(const glm::mat4 &viewProjection);
		void Clear();
		bool Add(const DrawData &drawData);
		void BufferConstants();
		void BufferData();

		size_t GetIndexCount() const
		{
			return indices.GetIndexCount();
		}

		size_t GetMaxIndexCount() const
		{
			return indices.GetMaxIndexCount();
		}

		size_t GetVertexCount() const
		{
			return vertices.GetElementCount();
		}

		size_t GetMaxVertices() const
		{
			return vertices.GetMaxElementCount();
		}

		size_t GetTextureCount() const
		{
			return textures.GetTextures().GetTextureCount();
		}

		size_t GetMaxTextureCount() const
		{
			return textures.GetTextures().GetMaxTextureCount();
		}

	private:
		bool CanContain(const DrawData &drawData) const;
		bool TryAdd(const DrawData &drawData);
		void AddIndices(const DrawData &drawData);
		void AddVertices(const DrawData &drawData, size_t textureSlot);
	};
}
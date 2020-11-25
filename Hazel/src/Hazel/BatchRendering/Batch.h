#pragma once

#include "BatchInfo.h"
#include "BatchMesh.h"
#include "BatchTextures.h"
#include "BatchBuffers.h"
#include "BatchShader.h"
#include "Hazel/Rendering/DrawData.h"

namespace Hazel
{
	class Batch
	{
	private:
		BatchMesh mesh;
		BatchTextures textures;
		BatchBuffers buffers;
		BatchShader shader;

	public:
		Batch(GraphicsContext &graphicsContext, const BatchInfo &info);

		void SetViewProjectionMatrix(const glm::mat4 &viewProjection);
		void Clear();
		bool Add(const DrawData &drawData);
		void BufferData();
		void BindBuffers() const;
		void BindTextures() const;

		inline size_t GetIndexCount() const
		{
			return mesh.GetIndices().GetIndexCount();
		}

		inline size_t GetMaxIndexCount() const
		{
			return mesh.GetIndices().GetMaxIndexCount();
		}

		inline size_t GetVertexCount() const
		{
			return mesh.GetVertices().GetElementCount();
		}

		inline size_t GetMaxVertices() const
		{
			return mesh.GetVertices().GetMaxElementCount();
		}

		inline size_t GetTextureCount() const
		{
			return textures.GetTextures().GetTextureCount();
		}

		inline size_t GetMaxTextureCount() const
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
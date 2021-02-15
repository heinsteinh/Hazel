#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Rendering/Renderer/RenderCommand.h"
#include "RendererIndices.h"
#include "RendererVertices.h"
#include "RendererTextures.h"

namespace Hazel
{
	class RendererBatch
	{
	private:
		RendererIndices indices;
		RendererVertices vertices;
		RendererTextures textures;

	public:
		RendererBatch(const RendererInfo &info);

		bool Add(const RenderCommand &command);
		void Clear();

		const RendererIndices &GetIndices() const
		{
			return indices;
		}

		const RendererVertices &GetVertices() const
		{
			return vertices;
		}

		const RendererTextures &GetTextures() const
		{
			return textures;
		}

		void SetIndexFormat(IndexFormat indexFormat)
		{
			indices.SetIndexFormat(indexFormat);
		}

		void SetVertexLayout(const VertexLayout &vertexLayout)
		{
			vertices.SetVertexLayout(vertexLayout);
		}

		bool IsEmpty() const
		{
			return indices.GetIndexCount() == 0;
		}

		bool CanContain(const Mesh &mesh)
		{
			return indices.CanContain(mesh.Indices.GetIndexCount())
				&& vertices.CanContain(mesh.Vertices.GetVertexCount());
		}
	};
}
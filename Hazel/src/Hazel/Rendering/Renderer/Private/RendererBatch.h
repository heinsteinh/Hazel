#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Rendering/Renderer/RenderCommand.h"
#include "RendererIndices.h"
#include "RendererVertices.h"
#include "RendererTextures.h"
#include "RendererIndexBuilder.h"
#include "RendererVertexBuilder.h"

namespace Hazel
{
	class RendererBatch
	{
	private:
		RendererIndices indices;
		RendererVertices vertices;
		RendererTextures textures;

	public:
		RendererBatch(const RendererInfo &info)
			: indices(info.IndexBufferSize),
			vertices(info.VertexBufferSize),
			textures(*info.GraphicsContext, info.TextureSlotCount)
		{
		}

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

		bool Add(const RenderCommand &command)
		{
			if (!CanContain(*command.Mesh))
			{
				return false;
			}
			auto textureSlot = textures.Add(command.Texture);
			if (!textureSlot)
			{
				return false;
			}
			RendererIndexBuilder::AddIndices(indices, command.Mesh->Indices, vertices.GetVertexCount());
			RendererVertexBuilder::AddVertices(vertices, command, *textureSlot);
			return true;
		}

		void Clear()
		{
			indices.Clear();
			vertices.Clear();
			textures.Clear();
		}
	};
}
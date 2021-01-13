#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Rendering/Renderer/RendererStatistics.h"
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
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;

	public:
		RendererBatch(const RendererInfo &info)
			: indices(info.IndexBufferSize),
			vertices(info.VertexBufferSize),
			textures(*info.GraphicsContext, info.TextureSlotCount),
			indexBuffer(info.GraphicsContext->CreateIndexBuffer(info.IndexBufferSize)),
			vertexBuffer(info.GraphicsContext->CreateVertexBuffer(info.VertexBufferSize))
		{
			info.GraphicsContext->SetIndexBuffer(indexBuffer.get());
			info.GraphicsContext->SetVertexBuffer(vertexBuffer.get());
		}

		size_t GetIndexCount() const
		{
			return indices.GetIndexCount();
		}

		size_t GetVertexCount() const
		{
			return vertices.GetVertexCount();
		}

		size_t GetTextureCount() const
		{
			return textures.GetTextureCount();
		}

		void SetIndexFormat(IndexFormat indexFormat)
		{
			indices.SetIndexFormat(indexFormat);
		}

		void SetVertexLayout(const VertexLayout &vertexLayout)
		{
			vertices.SetVertexLayout(vertexLayout);
		}

		bool Add(const RenderCommand &command)
		{
			if (!CanContain(*command.Mesh))
			{
				return false;
			}
			auto textureSlot = textures.Add(command.Material->Texture);
			if (!textureSlot)
			{
				return false;
			}
			AddIndices(command.Mesh->Indices);
			AddVertices(command, *textureSlot);
			return true;
		}

		void BufferData()
		{
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
			textures.Bind();
		}

		void Clear()
		{
			indices.Clear();
			vertices.Clear();
			textures.Clear();
		}

	private:
		bool CanContain(const Mesh &mesh)
		{
			return indices.CanContain(mesh.Indices.GetIndexCount())
				&& vertices.CanContain(mesh.Vertices.GetVertexCount());
		}

		void AddIndices(const IndexArray &indices)
		{
			RendererIndexBuilder::AddIndices(indices, this->indices, vertices.GetVertexCount());
		}

		void AddVertices(const RenderCommand &command, size_t textureSlot)
		{
			RendererVertexBuilder::AddVertices(vertices, command, textureSlot);
		}
	};
}
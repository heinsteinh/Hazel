#include "RendererBatch.h"

#include "RendererIndexBuilder.h"
#include "RendererVertexBuilder.h"

namespace Hazel
{
	RendererBatch::RendererBatch(const RendererInfo &info)
		: indices(info.IndexFormat, info.IndexBufferSize),
		vertices(info.VertexBufferSize),
		textures(*info.GraphicsContext, info.TextureSlotCount)
	{
	}

	bool RendererBatch::Add(const RenderCommand &command)
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

	void RendererBatch::Clear()
	{
		indices.Clear();
		vertices.Clear();
		textures.Clear();
	}
}
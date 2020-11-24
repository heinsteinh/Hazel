#include "Batch.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	Batch::Batch(const RendererInfo &info)
		: graphicsContext(info.GraphicsContext),
		indices(info.MaxIndexCount, info.IndexFormat),
		vertices(info.MaxVertexCount),
		textures(graphicsContext->GetTextureSlotCount()),
		buffers(info),
		whiteTexture(TextureBuilder(*graphicsContext).BuildFlatTexture(glm::vec4(1.0f)))
	{
		textures.Add(whiteTexture);
		BindBuffers();
	}

	void Batch::PushConstant(const void *data, size_t size)
	{
		buffers.BufferConstant(data, size);
	}

	void Batch::Clear()
	{
		indices.Clear();
		vertices.Clear();
		textures.Resize(1);
	}

	bool Batch::Add(const DrawData &drawData)
	{
		return CanContain(drawData) && TryAdd(drawData);
	}

	void Batch::BufferData()
	{
		buffers.BufferIndices(indices.GetData(), indices.GetSize());
		buffers.BufferVertices(vertices.GetData(), vertices.GetSize());
	}

	void Batch::BindBuffers() const
	{
		buffers.Bind(*graphicsContext);
	}

	void Batch::BindTextures() const
	{
		textures.Bind(*graphicsContext);
	}

	bool Batch::CanContain(const DrawData &drawData) const
	{
		return indices.CanContain(drawData.Mesh->Indices.size())
			&& vertices.CanContain(drawData.Mesh->Indices.size());
	}

	bool Batch::TryAdd(const DrawData &drawData)
	{
		auto textureSlot = drawData.Texture ? textures.Add(drawData.Texture) : 0;
		if (!textureSlot)
		{
			return false;
		}
		AddIndices(drawData);
		AddVertices(drawData, textureSlot.value());
		return true;
	}

	void Batch::AddIndices(const DrawData &drawData)
	{
		for (auto index : drawData.Mesh->Indices)
		{
			indices.Add(static_cast<uint32_t>(vertices.GetElementCount() + index));
		}
	}

	void Batch::AddVertices(const DrawData &drawData, size_t textureSlot)
	{
		auto matrix = drawData.Transform.ToMatrix();
		for (const auto &vertexInfo : drawData.Mesh->Vertices)
		{
			auto &vertex = vertices.Emplace();
			vertex.Position = matrix * vertexInfo.Position;
			vertex.Color = vertexInfo.Color;
			vertex.TextureCoordinate = drawData.Texture.MapCoordinates(vertexInfo.TextureCoordinate);
			vertex.TextureIndex = static_cast<float>(textureSlot);
		};
	}
}
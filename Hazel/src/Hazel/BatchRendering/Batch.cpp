#include "Batch.h"

namespace Hazel
{
	Batch::Batch(GraphicsContext &graphicsContext, const BatchInfo &info)
		: indices(info.MaxIndexCount, info.IndexFormat),
		vertices(info.MaxVertexCount),
		textures(graphicsContext, info.MaxTextureSlotCount),
		buffers(graphicsContext, info),
		shader(graphicsContext)
	{
		graphicsContext.SetShader(shader);
	}

	void Batch::SetViewProjectionMatrix(const glm::mat4 &viewProjection)
	{
		buffers.BufferViewProjectionMatrix(viewProjection);
	}

	void Batch::Clear()
	{
		indices.Clear();
		vertices.Clear();
		textures.Clear();
	}

	bool Batch::Add(const DrawData &drawData)
	{
		return CanContain(drawData) && TryAdd(drawData);
	}

	void Batch::BufferData()
	{
		buffers.BufferIndices(indices);
		buffers.BufferVertices(vertices);
	}

	void Batch::BindBuffers() const
	{
		buffers.Bind();
	}

	void Batch::BindTextures() const
	{
		textures.Bind();
	}

	bool Batch::CanContain(const DrawData &drawData) const
	{
		return indices.CanContain(drawData.Mesh->Indices.size())
			&& vertices.CanContain(drawData.Mesh->Vertices.size());
	}

	bool Batch::TryAdd(const DrawData &drawData)
	{
		auto textureSlot = textures.Add(drawData.Texture);
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
			vertex.TextureCoordinate = drawData.Texture.GetSourceCoordinates(vertexInfo.TextureCoordinate);
			vertex.TextureIndex = static_cast<float>(textureSlot);
		};
	}
}
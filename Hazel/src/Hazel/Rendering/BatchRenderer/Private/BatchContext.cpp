#include "BatchContext.h"

#include "Hazel/Core/Geometry/MvpMatrix.h"

namespace Hazel
{
	BatchContext::BatchContext(GraphicsContext &graphicsContext, const BatchInfo &info)
		: indices(info.MaxIndexCount, info.IndexFormat),
		vertices(info.MaxVertexCount),
		textures(graphicsContext, info.MaxTextureSlotCount),
		buffers(graphicsContext, info),
		shader(graphicsContext)
	{
		graphicsContext.SetShader(shader);
	}

	void BatchContext::SetViewProjectionMatrix(const glm::mat4 &viewProjection)
	{
		constants.ViewProjection = viewProjection;
	}

	void BatchContext::Clear()
	{
		indices.Clear();
		vertices.Clear();
		textures.Clear();
	}

	bool BatchContext::Add(const DrawData &drawData)
	{
		if (!drawData.Mesh)
		{
			return true;
		}
		return CanContain(drawData) && TryAdd(drawData);
	}

	void BatchContext::BufferConstants()
	{
		buffers.BufferConstants(constants);
	}

	void BatchContext::BufferData()
	{
		buffers.BufferIndices(indices);
		buffers.BufferVertices(vertices);
	}

	bool BatchContext::CanContain(const DrawData &drawData) const
	{
		return indices.CanContain(drawData.Mesh->Indices.size())
			&& vertices.CanContain(drawData.Mesh->Vertices.size());
	}

	bool BatchContext::TryAdd(const DrawData &drawData)
	{
		auto textureSlot = textures.Add(drawData.GetTexture());
		if (!textureSlot)
		{
			return false;
		}
		AddIndices(drawData);
		AddVertices(drawData, textureSlot.value());
		return true;
	}

	void BatchContext::AddIndices(const DrawData &drawData)
	{
		for (auto index : drawData.Mesh->Indices)
		{
			indices.Add(static_cast<uint32_t>(vertices.GetElementCount() + index));
		}
	}

	void BatchContext::AddVertices(const DrawData &drawData, size_t textureSlot)
	{
		for (const auto &vertexInfo : drawData.Mesh->Vertices)
		{
			auto &vertex = vertices.Emplace();
			vertex.Position = drawData.ApplyTransform(vertexInfo.Position);
			vertex.TextureCoordinate = drawData.GetTextureCoordinates(vertexInfo.TextureCoordinate);
			vertex.TextureIndex = static_cast<float>(textureSlot);
			vertex.Color = drawData.GetColor(vertexInfo);
		};
	}
}
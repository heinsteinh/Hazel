#include "Batch.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Hazel
{
	Batch::Batch(RenderApiFactory &factory, const BatchInfo &info)
		: indices(info.MaxIndices),
		vertices(info.MaxVertices),
		textures(info.MaxTextures),
		buffer(factory, info),
		whiteTexture(TextureBuilder(factory).BuildFlatTexture(glm::vec4(1.0f)))
	{
		textures.Add(whiteTexture);
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
		buffer.BufferIndices(indices.GetData(), indices.GetSize());
		buffer.BufferVertices(vertices.GetData(), vertices.GetSize());
	}

	void Batch::Bind() const
	{
		buffer.Bind();
		textures.Bind();
	}

	bool Batch::CanContain(const DrawData &drawData) const
	{
		return indices.CanContain(drawData.Mesh.Indices.size())
			&& vertices.CanContain(drawData.Mesh.Indices.size());
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
		for (auto index : drawData.Mesh.Indices)
		{
			indices.Add(static_cast<uint32_t>(vertices.GetSize() + index));
		}
	}

	void Batch::AddVertices(const DrawData &drawData, size_t textureSlot)
	{
		auto matrix = drawData.Transform.ToMatrix();
		for (const auto &vertex : drawData.Mesh.Vertices)
		{
			vertices.Add({
				matrix * vertex.Position,
				vertex.Color,
				drawData.Texture.MapCoordinates(vertex.TextureCoordinate),
				static_cast<float>(textureSlot)});
		}
	}
}
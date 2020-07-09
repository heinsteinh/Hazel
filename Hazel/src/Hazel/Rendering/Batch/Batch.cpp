#include "Batch.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Hazel
{
	Batch::Batch(const BatchInfo &info)
		: indices(info.MaxIndices),
		vertices(info.MaxVertices),
		textures(info.MaxTextures),
		buffer(info),
		whiteTexture(TextureBuilder(info.Factory).Build(glm::vec4(1.0f)))
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
		return indices.CanContain(drawData.Indices.size())
			&& vertices.CanContain(drawData.Meshes.size());
	}

	bool Batch::TryAdd(const DrawData &drawData)
	{
		auto slot = drawData.Texture ? textures.Add(drawData.Texture) : 0;
		if (!slot)
		{
			return false;
		}
		AddIndices(drawData);
		AddVertices(drawData, slot.value());
		return true;
	}

	void Batch::AddIndices(const DrawData &drawData)
	{
		for (auto index : drawData.Indices)
		{
			indices.Add(static_cast<unsigned int>(vertices.GetSize() + index));
		}
	}

	void Batch::AddVertices(const DrawData &drawData, size_t slot)
	{
		auto matrix = drawData.Transform.ToMatrix();
		for (const auto &mesh : drawData.Meshes)
		{
			vertices.Add({
				matrix * mesh.Position,
				mesh.Color,
				mesh.TextureCoordinate,
				static_cast<float>(slot)});
		}
	}
}
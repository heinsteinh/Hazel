#include "Batch.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Hazel
{
	Batch::Batch(const BatchInfo &info)
		: indexes(info.MaxIndexes),
		vertices(info.MaxVertices),
		textures(info.MaxTextures),
		buffer(info),
		whiteTexture(TextureBuilder(info.Factory).Build(glm::vec4(1.0f)))
	{
	}

	void Batch::Clear()
	{
		indexes.Clear();
		vertices.Clear();
		textures.Clear();
		textures.Add(whiteTexture);
	}

	void Batch::Add(const DrawData &drawData)
	{
		AddIndexes(drawData);
		AddVertices(drawData);
	}

	void Batch::BufferData()
	{
		buffer.SetIndexes(indexes.GetData(), indexes.GetSize() * sizeof(unsigned int));
		buffer.SetVertices(vertices.GetData(), vertices.GetSize() * sizeof(Vertex));
	}

	void Batch::Bind() const
	{
		buffer.Bind();
		textures.Bind();
	}

	void Batch::AddIndexes(const DrawData &drawData)
	{
		for (auto index : drawData.Indexes)
		{
			indexes.Add(static_cast<unsigned int>(vertices.GetSize() + index));
		}
	}

	void Batch::AddVertices(const DrawData &drawData)
	{
		auto matrix = drawData.Transform.ToMatrix();
		for (const auto &mesh : drawData.Meshes)
		{
			vertices.Add({
				matrix * mesh.Position,
				mesh.Color,
				mesh.TextureCoordinate,
				AddTexture(mesh.Texture)});
		}
	}

	float Batch::AddTexture(const std::shared_ptr<Texture2D> &texture)
	{
		return static_cast<float>(textures.Add(texture ? texture : whiteTexture));
	}
}
#pragma once

#include "TemplateBatch.h"
#include "TextureBatch.h"
#include "BatchBuffer.h"
#include "DrawData.h"
#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Hazel
{
	class Batch
	{
	private:
		TemplateBatch<unsigned int> indexes;
		TemplateBatch<Vertex> vertices;
		TextureBatch textures;
		BatchBuffer buffer;
		std::shared_ptr<Texture2D> defaultTexture;

	public:
		inline Batch(const BatchInfo &info)
			: indexes(info.MaxIndexes),
			vertices(info.MaxVertices),
			textures(info.MaxTextures),
			buffer(info),
			defaultTexture(TextureBuilder(info.Factory).Build(glm::vec4(1.0f)))
		{
		}

		constexpr size_t GetIndexCount() const
		{
			return indexes.GetSize();
		}

		inline void Clear()
		{
			indexes.Clear();
			vertices.Clear();
			textures.Clear();
		}

		inline void Add(const DrawData &drawData)
		{
			for (auto index : drawData.Indexes)
			{
				indexes.Add(static_cast<unsigned int>(vertices.GetSize() + index));
			}
			for (const auto &mesh : drawData.Meshes)
			{
				vertices.Add(mesh.ToVertex(AddTexture(mesh.Texture)));
			}
		}

		inline void BufferData()
		{
			buffer.SetIndexes(indexes.GetData(), indexes.GetSize() * sizeof(unsigned int));
			buffer.SetVertices(vertices.GetData(), vertices.GetSize() * sizeof(Vertex));
		}

		inline void Bind() const
		{
			buffer.Bind();
			textures.Bind();
		}

	private:
		inline int AddTexture(const std::shared_ptr<Texture2D> &texture)
		{
			return static_cast<int>(textures.Add(texture ? texture : defaultTexture));
		}
	};
}
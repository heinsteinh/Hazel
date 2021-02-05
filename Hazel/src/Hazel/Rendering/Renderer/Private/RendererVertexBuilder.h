#pragma once

#include "Hazel/Rendering/Mesh/Vertex.h"
#include "Hazel/Rendering/Renderer/RenderCommand.h"

namespace Hazel
{
	class RendererVertexBuilder
	{
	public:
		static void AddVertices(RendererVertices &vertices, const RenderCommand &object, size_t textureSlot)
		{
			object.Mesh->Vertices.ForEach([&](ConstantVertex vertex)
			{
				BuildVertex(vertices.Add(vertex), object, textureSlot);
			});
		}

		static void BuildVertex(Vertex vertex, const RenderCommand &object, size_t textureSlot)
		{
			auto &properties = (*object.Shader)->GetProperties();
			ApplyTransform(vertex, properties, object.Transform);
			UpdateColor(vertex, properties, object.Color);
			UpdateTextureCoordinates(vertex, properties, object.Texture);
			UpdateTextureSlot(vertex, properties, textureSlot);
		}

	private:
		static void ApplyTransform(Vertex vertex, const ShaderProperties &properties, const Transform *transform)
		{
			if (transform && properties.PositionIndex)
			{
				auto &position = vertex.GetAttribute<glm::vec3>(*properties.PositionIndex);
				position = transform->Apply(position);
			}
		}

		static void UpdateColor(Vertex vertex, const ShaderProperties &properties, const glm::vec4 *color)
		{
			if (color && properties.ColorIndex)
			{
				vertex.GetAttribute<glm::vec4>(*properties.ColorIndex) *= *color;
			}
		}

		static void UpdateTextureCoordinates(Vertex vertex, const ShaderProperties &properties, const SubTexture *texture)
		{
			if (texture && properties.TextureCoordinatesIndex)
			{
				auto &coordinates = vertex.GetAttribute<glm::vec2>(*properties.TextureCoordinatesIndex);
				coordinates = texture->GetSourceCoordinates(coordinates);
			}
		}

		static void UpdateTextureSlot(Vertex vertex, const ShaderProperties &properties, size_t textureSlot)
		{
			if (properties.TextureSlotIndex)
			{
				vertex.GetAttribute<float>(*properties.TextureSlotIndex) = static_cast<float>(textureSlot);
			}
		}
	};
}
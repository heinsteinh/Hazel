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
			ApplyTransform(vertex, *object.Mesh, object.Transform);
			UpdateColor(vertex, *object.Mesh, object.Color);
			UpdateTextureCoordinates(vertex, *object.Mesh, object.Texture);
			UpdateTextureSlot(vertex, *object.Mesh, textureSlot);
		}

	private:
		static void ApplyTransform(Vertex vertex, const Mesh &mesh, const Transform *transform)
		{
			if (transform && mesh.InputMap.PositionIndex)
			{
				auto &position = vertex.GetAttribute<glm::vec3>(*mesh.InputMap.PositionIndex);
				position = transform->Apply(position);
			}
		}

		static void UpdateColor(Vertex vertex, const Mesh &mesh, const glm::vec4 *color)
		{
			if (color && mesh.InputMap.ColorIndex)
			{
				vertex.GetAttribute<glm::vec4>(*mesh.InputMap.ColorIndex) *= *color;
			}
		}

		static void UpdateTextureCoordinates(Vertex vertex, const Mesh &mesh, const SubTexture *texture)
		{
			if (texture && mesh.InputMap.TextureCoordinatesIndex)
			{
				auto &coordinates = vertex.GetAttribute<glm::vec2>(*mesh.InputMap.TextureCoordinatesIndex);
				coordinates = texture->GetSourceCoordinates(coordinates);
			}
		}

		static void UpdateTextureSlot(Vertex vertex, const Mesh &mesh, size_t textureSlot)
		{
			if (mesh.InputMap.TextureSlotIndex)
			{
				vertex.GetAttribute<float>(*mesh.InputMap.TextureSlotIndex) = static_cast<float>(textureSlot);
			}
		}
	};
}
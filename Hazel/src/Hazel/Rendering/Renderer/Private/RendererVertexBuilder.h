#pragma once

#include "Hazel/Rendering/Meshes/Vertex.h"
#include "Hazel/Rendering/Renderer/RenderCommand.h"

namespace Hazel
{
	class RendererVertexBuilder
	{
	public:
		static void AddVertices(RendererVertices &vertices, const RenderCommand &command, size_t textureSlot)
		{
			command.Mesh->Vertices.ForEach([&](ConstantVertex vertex)
			{
				BuildVertex(vertices.Add(vertex), command, textureSlot);
			});
		}

		static void BuildVertex(Vertex vertex, const RenderCommand &command, size_t textureSlot)
		{
			ApplyTransform(vertex, *command.Mesh, command.Transform);
			UpdateColor(vertex, *command.Mesh, command.Material->Color);
			UpdateTextureCoordinates(vertex, *command.Mesh, command.Material->Texture);
			UpdateTextureSlot(vertex, *command.Mesh, textureSlot);
		}

	private:
		static void ApplyTransform(Vertex vertex, const Mesh &mesh, const Transform *transform)
		{
			if (transform && mesh.PositionIndex)
			{
				auto &position = vertex.GetAttribute<glm::vec3>(*mesh.PositionIndex);
				position = transform->Apply(position);
			}
		}

		static void UpdateColor(Vertex vertex, const Mesh &mesh, const glm::vec4 &color)
		{
			if (mesh.ColorIndex)
			{
				vertex.GetAttribute<glm::vec4>(*mesh.ColorIndex) *= color;
			}
		}

		static void UpdateTextureCoordinates(Vertex vertex, const Mesh &mesh, const SubTexture &texture)
		{
			if (mesh.TextureCoordinatesIndex)
			{
				auto &coordinates = vertex.GetAttribute<glm::vec2>(*mesh.TextureCoordinatesIndex);
				coordinates = texture.GetSourceCoordinates(coordinates);
			}
		}

		static void UpdateTextureSlot(Vertex vertex, const Mesh &mesh, size_t textureSlot)
		{
			if (mesh.TextureSlotIndex)
			{
				vertex.GetAttribute<float>(*mesh.TextureSlotIndex) = static_cast<float>(textureSlot);
			}
		}
	};
}
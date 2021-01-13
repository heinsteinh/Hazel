#pragma once

#include <memory>

#include "Hazel/Rendering/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/Rendering/Meshes/Mesh.h"
#include "Vertex2D.h"

namespace Hazel
{
	class SquareMesh
	{
	public:
		static std::shared_ptr<Mesh> CreateMesh()
		{
			auto mesh = std::make_shared<Mesh>();
			mesh->PrimitiveTopology = PrimitiveTopology::Triangles;
			AddIndices(*mesh);
			AddVertexLayout(*mesh);
			AddVertices(*mesh);
			return mesh;
		}

	private:
		static void AddIndices(Mesh &mesh)
		{
			mesh.Indices.SetIndexFormat(IndexFormat::UInt16);
			mesh.Indices.Reserve(6);
			mesh.Indices.AddIndex<uint16_t>(0);
			mesh.Indices.AddIndex<uint16_t>(1);
			mesh.Indices.AddIndex<uint16_t>(2);
			mesh.Indices.AddIndex<uint16_t>(2);
			mesh.Indices.AddIndex<uint16_t>(3);
			mesh.Indices.AddIndex<uint16_t>(0);
		}

		static void AddVertexLayout(Mesh &mesh)
		{
			mesh.Vertices.SetLayout(Vertex2D::Layout);
			mesh.PositionIndex = Vertex2D::PositionIndex;
			mesh.ColorIndex = Vertex2D::ColorIndex;
			mesh.TextureCoordinatesIndex = Vertex2D::TextureCoordinatesIndex;
			mesh.TextureSlotIndex = Vertex2D::TextureSlotIndex;
		}

		static void AddVertices(Mesh &mesh)
		{
			mesh.Vertices.Reserve(4);
			auto &topLeft = mesh.Vertices.Emplace<Vertex2D>();
			topLeft.Position = {-0.5f, 0.5f, 0.0f};
			topLeft.TextureCoordinates = {0.0f, 1.0f};
			auto &topRight = mesh.Vertices.Emplace<Vertex2D>();
			topRight.Position = {0.5f, 0.5f, 0.0f};
			topRight.TextureCoordinates = {1.0f, 1.0f};
			auto &bottomRight = mesh.Vertices.Emplace<Vertex2D>();
			bottomRight.Position = {0.5f, -0.5f, 0.0f};
			bottomRight.TextureCoordinates = {1.0f, 0.0f};
			auto &bottomLeft = mesh.Vertices.Emplace<Vertex2D>();
			bottomLeft.Position = {-0.5f, -0.5f, 0.0f};
			bottomLeft.TextureCoordinates = {0.0f, 0.0f};
		}
	};
}
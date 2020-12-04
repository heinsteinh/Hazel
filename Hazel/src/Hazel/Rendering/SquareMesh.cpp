#include "SquareMesh.h"

namespace Hazel
{
	std::shared_ptr<Mesh> SquareMesh::CreateMesh()
	{
		auto result = std::make_shared<Mesh>();
		result->Indices = {0, 1, 2, 2, 3, 0};
		result->Vertices.resize(4);
		result->Vertices[0].Position = {-0.5f, 0.5f, 0.0f};
		result->Vertices[0].TextureCoordinate = {0.0f, 1.0f};
		result->Vertices[1].Position = {0.5f, 0.5f, 0.0f};
		result->Vertices[1].TextureCoordinate = {1.0f, 1.0f};
		result->Vertices[2].Position = {0.5f, -0.5f, 0.0f};
		result->Vertices[2].TextureCoordinate = {1.0f, 0.0f};
		result->Vertices[3].Position = {-0.5f, -0.5f, 0.0f};
		result->Vertices[3].TextureCoordinate = {0.0f, 0.0f};
		return result;
	}
}
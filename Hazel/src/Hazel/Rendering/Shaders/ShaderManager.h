#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Shader.h"

namespace Hazel
{
	class ShaderManager
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;

	public:
		ShaderManager(GraphicsContext &graphicsContext)
			: graphicsContext(&graphicsContext)
		{
		}
	};
}
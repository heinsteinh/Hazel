#pragma once

#include <string>
#include <unordered_map>

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "MaterialShader.h"

namespace Hazel
{
	class ShaderManager
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::unordered_map<std::string, std::shared_ptr<MaterialShader>> shaders;

	public:
		ShaderManager(GraphicsContext &graphicsContext)
			: graphicsContext(&graphicsContext)
		{
		}

		std::shared_ptr<MaterialShader> GetShader(const std::string &key)
		{
			auto i = shaders.find(key);
			return i == shaders.end() ? nullptr : i->second;
		}
	};
}
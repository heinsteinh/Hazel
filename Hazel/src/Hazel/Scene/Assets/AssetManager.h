#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <functional>

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class Script;

	class AssetManager
	{
	public:
		using ScriptFactory = std::function<std::unique_ptr<Script>()>;

	private:
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
		std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
		std::unordered_map<std::string, ScriptFactory> scriptFactories;

	public:
		std::shared_ptr<Shader> GetShader(const std::string &name) const;
		const std::shared_ptr<Shader> &AddShader(const std::shared_ptr<Shader> &shader);
		std::shared_ptr<Texture> GetTexture(const std::string &name) const;
		const std::shared_ptr<Texture> &AddTexture(const std::shared_ptr<Texture> &texture);
		std::unique_ptr<Script> CreateScript(const std::string &name) const;
		void AddScriptFactory(const std::string &name, const ScriptFactory &factory);
	};
}
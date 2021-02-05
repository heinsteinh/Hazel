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
	class NativeScript;

	class AssetManager
	{
	public:
		using ScriptFactory = std::function<std::unique_ptr<NativeScript>(const std::string &)>;

	private:
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
		std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
		std::unordered_map<std::string, ScriptFactory> scriptFactories;

	public:
		std::shared_ptr<Shader> GetShader(const std::string &name) const
		{
			auto i = shaders.find(name);
			return i == shaders.end() ? nullptr : i->second;
		}

		const std::shared_ptr<Shader> &AddShader(const std::shared_ptr<Shader> &shader)
		{
			return shaders[shader->GetName()] = shader;
		}

		std::shared_ptr<Texture> GetTexture(const std::string &name) const
		{
			auto i = textures.find(name);
			return i == textures.end() ? nullptr : i->second;
		}

		const std::shared_ptr<Texture> &AddTexture(const std::shared_ptr<Texture> &texture)
		{
			return textures[texture->GetName()] = texture;
		}

		std::unique_ptr<NativeScript> CreateScript(const std::string &name) const
		{
			auto i = scriptFactories.find(name);
			return i == scriptFactories.end() ? nullptr : i->second(name);
		}

		void AddScriptFactory(const std::string &name, const ScriptFactory &factory)
		{
			scriptFactories[name] = factory;
		}

		template<typename T>
		void AddScriptFactory(const std::string &name)
		{
			scriptFactories[name] = [](const std::string &name)
			{
				auto script = std::make_unique<T>();
				script->SetName(name);
				return script;
			};
		}
	};
}
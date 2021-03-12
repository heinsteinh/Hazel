#include "AssetManager.h"

#include "Script.h"

namespace Hazel
{
	std::shared_ptr<Shader> AssetManager::GetShader(const std::string &name) const
	{
		auto i = shaders.find(name);
		return i == shaders.end() ? nullptr : i->second;
	}

	const std::shared_ptr<Shader> &AssetManager::AddShader(const std::shared_ptr<Shader> &shader)
	{
		return shaders[shader->GetFilename()] = shader;
	}

	std::shared_ptr<Texture> AssetManager::GetTexture(const std::string &name) const
	{
		auto i = textures.find(name);
		return i == textures.end() ? nullptr : i->second;
	}

	const std::shared_ptr<Texture> &AssetManager::AddTexture(const std::shared_ptr<Texture> &texture)
	{
		return textures[texture->GetFilename()] = texture;
	}

	std::unique_ptr<Script> AssetManager::CreateScript(const std::string &name) const
	{
		auto i = scriptFactories.find(name);
		if (i == scriptFactories.end())
		{
			return nullptr;
		}
		auto script = i->second();
		script->SetName(name);
		return script;
	}

	void AssetManager::AddScriptFactory(const std::string &name, const ScriptFactory &factory)
	{
		scriptFactories[name] = factory;
	}
}
#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Textures/Texture.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"

namespace Hazel
{
	class TextureManager
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::unordered_map<std::string, std::shared_ptr<Texture>> textures;

	public:
		TextureManager() = default;

		TextureManager(GraphicsContext &graphicsContext)
			: graphicsContext(&graphicsContext)
		{
		}

		void SetGraphicsContext(GraphicsContext &graphicsContext)
		{
			this->graphicsContext = &graphicsContext;
		}

		const std::shared_ptr<Texture> &Load(const std::string &filename)
		{
			auto &texture = textures[filename];
			if (!texture)
			{
				texture = TextureFactory::CreateTextureFromFile(*graphicsContext, filename);
			}
			return texture;
		}

		const std::shared_ptr<Texture> &Reload(const std::string &filename)
		{
			return textures[filename] = TextureFactory::CreateTextureFromFile(*graphicsContext, filename);
		}

		void Unload(const std::string &filename)
		{
			textures.erase(filename);
		}

		void Clear()
		{
			textures.clear();
		}
	};
}
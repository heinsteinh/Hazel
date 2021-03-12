#pragma once

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"

namespace Hazel
{
	class TextureDialog
	{
	private:
		SceneManagerView manager;

	public:
		TextureDialog(SceneManagerView manager)
			: manager(manager)
		{
		}

		std::shared_ptr<Texture> GetTextureFromUser()
		{
			FileDialog dialog(manager.GetWindow());
			if (dialog.GetOpenFilename())
			{
				return TryGetOrCreateTexture(dialog.GetFilename());
			}
			return nullptr;
		}

	private:
		std::shared_ptr<Texture> TryGetOrCreateTexture(const std::string &filename)
		{
			auto texture = TryGetTexture(filename);
			if (texture)
			{
				return texture;
			}
			return TryAddTexture(filename);
		}

		std::shared_ptr<Texture> TryGetTexture(const std::string &filename)
		{
			return manager.GetAssetManager().GetTexture(filename);
		}

		std::shared_ptr<Texture> TryAddTexture(const std::string &filename)
		{
			auto texture = TryCreateTexture(filename);
			if (texture)
			{
				return manager.GetAssetManager().AddTexture(texture);
			}
			return nullptr;
		}

		std::shared_ptr<Texture> TryCreateTexture(const std::string &filename)
		{
			return TextureFactory(manager.GetGraphicsContext()).TryCreateTextureFromFile(filename);
		}
	};
}
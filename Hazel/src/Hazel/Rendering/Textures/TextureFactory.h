#pragma once

#include <array>

#include "Hazel/Core/Images/Image.h"
#include "Hazel/Core/FileSystem/Filename.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "TextureFormatHelper.h"

namespace Hazel
{
	class TextureFactory
	{
	private:
		GraphicsContext *graphicsContext = nullptr;

	public:
		TextureFactory(GraphicsContext &graphicsContext)
			: graphicsContext(&graphicsContext)
		{
		}

		std::shared_ptr<Texture> TryCreateTextureFromFile(const std::string &filename)
		{
			TextureInfo info;
			info.Filename = filename;
			return TryCreateTextureFromFile(info);
		}

		std::shared_ptr<Texture> TryCreateTextureFromFile(TextureInfo &info)
		{
			auto image = Image::FromFile(info.Filename);
			if (!image.IsValid() || image.IsEmpty())
			{
				return nullptr;
			}
			BuildTextureInfo(info, image);
			return CreateTexture(info, image.GetData());
		}

		std::shared_ptr<Texture> CreateFlatTexture(const glm::vec4 &color)
		{
			TextureInfo info;
			info.Format = TextureFormat::Rgba8;
			return CreateTexture(info, CreateFlatTextureData(color).data());
		}

	private:
		void BuildTextureInfo(TextureInfo &info, const Image &image)
		{
			if (info.Name.empty())
			{
				info.Name = Filename::GetBaseName(info.Filename);
			}
			info.Size = image.GetSize();
			info.Format = TextureFormatHelper::GetTextureFormat(image.GetChannelCount());
		}

		std::array<uint8_t, 4> CreateFlatTextureData(const glm::vec4 &color)
		{
			return
			{
				static_cast<uint8_t>(255.0f * color.r),
				static_cast<uint8_t>(255.0f * color.g),
				static_cast<uint8_t>(255.0f * color.b),
				static_cast<uint8_t>(255.0f * color.a)
			};
		}

		std::shared_ptr<Texture> CreateTexture(const TextureInfo &info, const void *data)
		{
			auto texture = graphicsContext->CreateTexture(info);
			texture->BufferData(data);
			return texture;
		}
	};
}
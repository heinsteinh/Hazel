#pragma once

#include "Hazel/Core/Images/Image.h"
#include "Hazel/Core/FileSystem/Filename.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "TextureFormatHelper.h"

namespace Hazel
{
	class TextureFactory
	{
	public:
		static std::shared_ptr<Texture> CreateTextureFromFile(GraphicsContext &graphicsContext, const std::string &filename)
		{
			auto image = Image::FromFile(filename);
			if (!image.IsValid())
			{
				return nullptr;
			}
			TextureInfo info;
			info.Name = Filename::GetBaseName(filename);
			info.Filename = filename;
			info.Size = image.GetSize();
			info.Data = image.GetData();
			info.Format = TextureFormatHelper::GetTextureFormat(image.GetChannelCount());
			auto texture = graphicsContext.CreateTexture(info);
			return texture;
		}

		static std::shared_ptr<Texture> CreateFlatTexture(GraphicsContext &graphicsContext, const glm::vec4 &color)
		{
			unsigned char data[4] = {
				static_cast<unsigned char>(255.0f * color.r),
				static_cast<unsigned char>(255.0f * color.g),
				static_cast<unsigned char>(255.0f * color.b),
				static_cast<unsigned char>(255.0f * color.a)
			};
			TextureInfo info;
			info.Size = {1.0f, 1.0f};
			info.Data = data;
			info.Format = TextureFormat::Rgba8;
			auto texture = graphicsContext.CreateTexture(info);
			return texture;
		}
	};
}
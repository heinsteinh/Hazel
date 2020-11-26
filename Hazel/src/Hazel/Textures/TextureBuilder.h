#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "TextureFormatHelper.h"
#include "Image.h"

namespace Hazel
{
	class TextureBuilder
	{
	private:
		GraphicsContext *graphicsContext = nullptr;

	public:
		constexpr TextureBuilder(GraphicsContext &graphicsContext)
			: graphicsContext(&graphicsContext)
		{
		}

		inline std::shared_ptr<Texture> CreateTextureFromFile(const std::string &filename)
		{
			Image image(filename);
			TextureInfo info;
			info.Size = {image.GetWidth(), image.GetHeight()};
			info.Format = TextureFormatHelper::GetTextureFormat(image.GetChannelCount());
			auto texture = graphicsContext->CreateTexture(info);
			texture->BufferData(image.GetData());
			return texture;
		}

		inline std::shared_ptr<Texture> CreateFlatTexture(const glm::vec4 &color)
		{
			TextureInfo info;
			info.Size = {1.0f, 1.0f};
			info.Format = TextureFormat::Rgba;
			auto texture = graphicsContext->CreateTexture(info);
			unsigned char data[4] = {
				static_cast<unsigned char>(255.0f * color.r),
				static_cast<unsigned char>(255.0f * color.g),
				static_cast<unsigned char>(255.0f * color.b),
				static_cast<unsigned char>(255.0f * color.a)
			};
			texture->BufferData(data);
			return texture;
		}
	};
}
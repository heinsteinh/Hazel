#pragma once

#include "Hazel/RenderApi/RenderApiFactory.h"
#include "Texture.h"
#include "TextureFormatHelper.h"
#include "Image.h"

namespace Hazel
{
	class TextureBuilder
	{
	private:
		RenderApiFactory &factory;

	public:
		constexpr TextureBuilder(RenderApiFactory &factory)
			: factory(factory)
		{
		}

		inline std::shared_ptr<Texture> BuildFromFile(const std::string &filename)
		{
			Image image(filename);
			auto texture = factory.CreateTexture({
				{image.GetWidth(), image.GetHeight()},
				TextureFormatHelper::GetTextureFormat(image.GetChannelCount())});
			texture->SetData(image.GetData());
			return texture;
		}

		inline std::shared_ptr<Texture> BuildFlatTexture(const glm::vec4 &color)
		{
			auto texture = factory.CreateTexture({{1, 1}, TextureFormat::Rgba});
			unsigned char data[4] = {
				static_cast<unsigned char>(255.0f * color.r),
				static_cast<unsigned char>(255.0f * color.g),
				static_cast<unsigned char>(255.0f * color.b),
				static_cast<unsigned char>(255.0f * color.a)
			};
			texture->SetData(data);
			return texture;
		}
	};
}
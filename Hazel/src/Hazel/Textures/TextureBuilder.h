#pragma once

#include "Hazel/RenderApi/RenderApiFactory.h"
#include "Texture.h"
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

		inline std::shared_ptr<Texture2D> BuildFromFile(const std::string &filename)
		{
			Image image(filename);
			auto texture = factory.CreateTexture2D({
				image.GetWidth(),
				image.GetHeight(),
				image.GetFormat()});
			texture->SetData(image.GetData());
			return texture;
		}

		inline std::shared_ptr<Texture2D> BuildFlatTexture(const glm::vec4 &color)
		{
			auto texture = factory.CreateTexture2D({1, 1, ColorFormat::Rgba});
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
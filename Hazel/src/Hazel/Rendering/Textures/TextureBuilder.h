#pragma once

#include "Hazel/Rendering/Core/RenderApiFactory.h"
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

		inline std::shared_ptr<Texture2D> Build(const std::string &filename)
		{
			Image image(filename);
			auto texture = factory.CreateTexture2D({
				image.GetWidth(),
				image.GetHeight(),
				image.GetFormat()});
			texture->SetData(image.GetData());
			return texture;
		}

		inline std::shared_ptr<Texture2D> Build(const glm::vec4 &data)
		{
			auto texture = factory.CreateTexture2D({1, 1, ColorFormat::Rgba});
			unsigned char color[4] = {
				static_cast<unsigned char>(255.0f * data.r),
				static_cast<unsigned char>(255.0f * data.g),
				static_cast<unsigned char>(255.0f * data.b),
				static_cast<unsigned char>(255.0f * data.a)
			};
			texture->SetData(color);
			return texture;
		}
	};
}
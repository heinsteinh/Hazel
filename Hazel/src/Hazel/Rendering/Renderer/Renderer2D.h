#pragma once

#include "Hazel/Core/Context.h"
#include "Hazel/Rendering/Camera/OrthographicCamera.h"
#include "RectangularSprite.h"
#include "Batch.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Drawer &drawer;
		std::shared_ptr<Shader> shader;
		std::shared_ptr<Texture2D> whiteTexture;
		BatchInfo batchInfo;
		Batch batch;

	public:
		Renderer2D(const Context &context);

		void BeginScene(const OrthographicCamera &camera);
		void Draw(const RectangularSprite &sprite);
		void EndScene();
	};
}
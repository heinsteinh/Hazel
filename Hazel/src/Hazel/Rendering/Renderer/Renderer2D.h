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
		const Context &context;
		SharedPtr<Shader> shader;
		SharedPtr<Texture> whiteTexture;
		BatchInfo batchInfo;
		Batch batch;

	public:
		Renderer2D(const Context &context);

		void BeginScene(const OrthographicCamera &camera);
		void Draw(RectangularSprite &sprite);
		void EndScene();
	};
}
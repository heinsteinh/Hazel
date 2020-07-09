#pragma once

#include "Hazel/Core/Context.h"
#include "Batch/DefaultShader.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Batch/GameObject.h"
#include "Batch/Batch.h"
#include "Batch/BatchException.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Drawer &drawer;
		DefaultShader shader;
		Batch batch;

	public:
		Renderer2D(const Context &context);
		Renderer2D(const Context &context, const BatchInfo &batchInfo);

		void BeginScene(const OrthographicCamera &camera);
		void Draw(const GameObject &object);
		void EndScene();
	};
}
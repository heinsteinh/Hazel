#pragma once

#include "Hazel/Core/Context.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Batch/GameObject.h"
#include "Batch/Batch.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Drawer &drawer;
		std::shared_ptr<Shader> shader;
		BatchInfo batchInfo;
		Batch batch;

	public:
		Renderer2D(const Context &context);

		void BeginScene(const OrthographicCamera &camera);
		void Draw(const GameObject &object);
		void EndScene();
	};
}
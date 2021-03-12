#pragma once

#include "Hazel/Core/Application/ApplicationSettings.h"
#include "Hazel/Core/Input/Input.h"
#include "Hazel/Core/Window/Window.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Scene/Assets/AssetManager.h"

namespace Hazel
{
	class SceneManager;

	class SceneManagerView
	{
	private:
		SceneManager *manager = nullptr;

	public:
		SceneManagerView() = default;

		SceneManagerView(SceneManager &manager);

		float GetDeltaTime() const;
		GraphicsApi &GetGraphicsApi() const;
		Window &GetWindow() const;
		GraphicsContext &GetGraphicsContext() const;
		ApplicationSettings &GetApplicationSettings() const;
		Input &GetInput() const;
		Renderer2D &GetRenderer() const;
		AssetManager &GetAssetManager() const;

		bool IsValid() const
		{
			return manager;
		}
	};
}
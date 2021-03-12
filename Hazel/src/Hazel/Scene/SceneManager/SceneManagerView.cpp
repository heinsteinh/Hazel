#include "SceneManagerView.h"

#include "SceneManager.h"

namespace Hazel
{
	SceneManagerView::SceneManagerView(SceneManager &manager)
		: manager(&manager)
	{
	}

	float SceneManagerView::GetDeltaTime() const
	{
		return manager->GetApplication().GetDeltaTime();
	}

	GraphicsApi &SceneManagerView::GetGraphicsApi() const
	{
		return manager->GetApplication().GetGraphicsApi();
	}

	Window &SceneManagerView::GetWindow() const
	{
		return manager->GetApplication().GetWindow();
	}

	GraphicsContext &SceneManagerView::GetGraphicsContext() const
	{
		return manager->GetApplication().GetGraphicsContext();
	}

	ApplicationSettings &SceneManagerView::GetApplicationSettings() const
	{
		return manager->GetApplication().GetSettings();
	}

	Input &SceneManagerView::GetInput() const
	{
		return manager->GetApplicationLayer().GetInput();
	}

	Renderer2D &SceneManagerView::GetRenderer() const
	{
		return manager->GetRenderer();
	}

	AssetManager &SceneManagerView::GetAssetManager() const
	{
		return manager->GetAssetManager();
	}
}
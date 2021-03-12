#include "ApplicationView.h"

#include "Private/ApplicationPrivate.h"

namespace Hazel
{
	ApplicationView::ApplicationView(ApplicationPrivate &application)
		: application(&application)
	{
	}

	float ApplicationView::GetDeltaTime() const
	{
		return application->DeltaTime;
	}

	GraphicsApi &ApplicationView::GetGraphicsApi() const
	{
		return *application->GraphicsApi;
	}

	Window &ApplicationView::GetWindow() const
	{
		return *application->Window;
	}

	GraphicsContext &ApplicationView::GetGraphicsContext() const
	{
		return *application->GraphicsContext;
	}

	ApplicationSettings &ApplicationView::GetSettings() const
	{
		return application->Settings;
	}
}
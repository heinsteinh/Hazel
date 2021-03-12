#pragma once

#include "Hazel/Core/Window/Window.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "ApplicationSettings.h"

namespace Hazel
{
	struct ApplicationPrivate;

	class ApplicationView
	{
	private:
		ApplicationPrivate *application = nullptr;

	public:
		ApplicationView() = default;
		ApplicationView(ApplicationPrivate &application);

		float GetDeltaTime() const;
		GraphicsApi &GetGraphicsApi() const;
		Window &GetWindow() const;
		GraphicsContext &GetGraphicsContext() const;
		ApplicationSettings &GetSettings() const;

		bool IsValid() const
		{
			return application;
		}
	};
}
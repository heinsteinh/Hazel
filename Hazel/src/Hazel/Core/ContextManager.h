#pragma once

#include "ApplicationInfo.h"
#include "Hazel/Window/Window.h"
#include "Context.h"
#include "Hazel/Layers/LayerManager.h"

namespace Hazel
{
	class ContextManager : public EventListener
	{
	private:
		Window window;
		Context context;
		LayerManager layerManager;
		bool windowClosed = false;

	public:
		ContextManager(const ApplicationInfo &info);

		Context &GetContext();
		LayerManager &GetLayerManager();
		bool HasWindowClosed() const;
		void OnUpdate();
		void MakeCurrent();

		virtual void OnEvent(Event &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
		virtual void OnWindowClosed(WindowCloseEvent &e) override;
	};
}
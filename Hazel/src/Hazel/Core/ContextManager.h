#pragma once

#include "ContextInfo.h"
#include "Hazel/Window/Window.h"
#include "Context.h"
#include "Hazel/Layers/LayerManager.h"

namespace Hazel
{
	class ContextManager : public EventListener
	{
	private:
		Window window;
		LayerManager layerManager;
		Context context;
		bool windowClosed = false;

	public:
		ContextManager(const ContextInfo &info);

		LayerManager &GetLayerManager();
		Context &GetContext();
		bool HasWindowClosed() const;
		void OnUpdate();
		void MakeCurrent();

		virtual void OnEvent(Event &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
		virtual void OnWindowClosed(WindowCloseEvent &e) override;
	};
}
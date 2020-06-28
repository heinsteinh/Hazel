#pragma once

#include "Context.h"
#include "Hazel/Events/EventManager.h"
#include "Hazel/Layers/LayerManager.h"

namespace Hazel
{
	class ContextManager : public EventListener
	{
	private:
		Context context;
		EventManager eventManager;
		LayerManager layerManager;
		SharedPtr<GraphicsContext> graphicsContext;
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
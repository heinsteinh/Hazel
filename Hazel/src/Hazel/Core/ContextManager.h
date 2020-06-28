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
		std::shared_ptr<GraphicsContext> graphicsContext;
		bool windowClosed = false;

	public:
		ContextManager(const ApplicationInfo &info);

		Context &GetContext();
		LayerManager &GetLayerManager();
		bool ShouldCloseWindow() const;
		void OnUpdate();
		void MakeCurrent();

		virtual void OnEvent(Event &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
		virtual void OnWindowClosed(WindowCloseEvent &e) override;
	};
}
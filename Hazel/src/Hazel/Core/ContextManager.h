#pragma once

#include "ContextData.h"
#include "Context.h"

namespace Hazel
{
	class ContextManager : public EventListener
	{
	private:
		ContextData contextData;
		Context context;
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
#include "ContextManager.h"

namespace Hazel
{
	ContextManager::ContextManager(const ApplicationInfo &info)
		: contextData(info),
		context(contextData.Window, contextData.Input, info.WindowInfo.RenderApi)
	{
		contextData.EventManager.SetEventListener(this);
		context.Drawer.SetClearColor({1.0f, 0.0f, 1.0f, 1.0f});
	}

	Context &ContextManager::GetContext()
	{
		return context;
	}

	LayerManager &ContextManager::GetLayerManager()
	{
		return contextData.LayerManager;
	}

	bool ContextManager::ShouldCloseWindow() const
	{
		return windowClosed;
	}

	void ContextManager::OnUpdate()
	{
		context.Drawer.Clear();
		contextData.EventManager.PollEvents();
		contextData.LayerManager.OnUpdate();
		contextData.Window.GetContext().SwapBuffers();
	}

	void ContextManager::MakeCurrent()
	{
		contextData.Window.GetContext().MakeCurrent();
		contextData.LayerManager.OnContextCurrent();
	}

	void ContextManager::OnEvent(Event &e)
	{
		contextData.LayerManager.OnEvent(e);
	}

	void ContextManager::OnWindowResized(WindowResizeEvent &e)
	{
		auto [width, height] = e.GetSize();
		context.Drawer.SetViewport({0.0f, width, 0.0f, height});
	}

	void ContextManager::OnWindowClosed(WindowCloseEvent &e)
	{
		windowClosed = true;
	}
}
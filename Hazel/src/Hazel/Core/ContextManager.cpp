#include "ContextManager.h"

namespace Hazel
{
	ContextManager::ContextManager(const ApplicationInfo &info)
		: window(info.WindowInfo),
		context(window, info.WindowInfo.RenderApi),
		layerManager(window.GetImGuiContext())
	{
		window.GetEventManager().SetEventListener(this);
	}

	Context &ContextManager::GetContext()
	{
		return context;
	}

	LayerManager &ContextManager::GetLayerManager()
	{
		return layerManager;
	}

	bool ContextManager::HasWindowClosed() const
	{
		return windowClosed;
	}

	void ContextManager::OnUpdate()
	{
		context.Drawer.Clear();
		window.GetEventManager().PollEvents();
		layerManager.OnUpdate();
		window.GetContext().SwapBuffers();
	}

	void ContextManager::MakeCurrent()
	{
		window.GetContext().MakeCurrent();
		window.GetImGuiContext().MakeCurrent();
	}

	void ContextManager::OnEvent(Event &e)
	{
		layerManager.OnEvent(e);
	}

	void ContextManager::OnWindowResized(WindowResizeEvent &e)
	{
		auto size = e.GetSize();
		context.Drawer.SetViewport({0.0f, size.Width, 0.0f, size.Height});
		layerManager.EnableLayersUpdate(!size.IsEmpty());
	}

	void ContextManager::OnWindowClosed(WindowCloseEvent &e)
	{
		windowClosed = true;
	}
}
#include "ContextManager.h"

namespace Hazel
{
	ContextManager::ContextManager(const ApplicationInfo &info)
		: window(info.WindowInfo),
		layerManager(window.GetImGuiContext()),
		context({
			layerManager,
			window.GetProperties(),
			window.GetInput(),
			info.WindowInfo.RenderApi.GetFactory(),
			info.WindowInfo.RenderApi.GetDrawer()})
	{
		window.GetEventManager().SetEventListener(this);
	}

	LayerManager &ContextManager::GetLayerManager()
	{
		return layerManager;
	}

	Context &ContextManager::GetContext()
	{
		return context;
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
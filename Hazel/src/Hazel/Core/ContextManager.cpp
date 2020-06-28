#include "ContextManager.h"

namespace Hazel
{
	ContextManager::ContextManager(const ApplicationInfo &info)
		: context(info),
		eventManager(context.Window),
		layerManager(context.Window),
		graphicsContext(context.Factory.CreateContext(context.Window))
	{
		eventManager.SetEventListener(this);
		context.Drawer.SetClearColor({255.0f, 0.0f, 255.0f, 1.0f});
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
		eventManager.PollEvents();
		layerManager.OnUpdate();
		graphicsContext->SwapBuffers();
	}

	void ContextManager::MakeCurrent()
	{
		graphicsContext->MakeCurrent();
		layerManager.OnContextCurrent();
	}

	void ContextManager::OnEvent(Event &e)
	{
		layerManager.OnEvent(e);
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
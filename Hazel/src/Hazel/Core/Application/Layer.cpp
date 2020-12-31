#include "Layer.h"

#include "Private/ApplicationContext.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(context, "The layer is not attached to a running application")

namespace Hazel
{
	Layer::Layer(const std::string &name)
		: name(name)
	{
	}

	const std::string &Layer::GetName() const
	{
		return name;
	}

	float Layer::GetDeltaTime() const
	{
		HZ_ASSERT_ATTACHED();
		return context->DeltaTime;
	}

	GraphicsApi &Layer::GetGraphicsApi() const
	{
		HZ_ASSERT_ATTACHED();
		return *context->GraphicsApi;
	}

	Window &Layer::GetWindow() const
	{
		HZ_ASSERT_ATTACHED();
		return *context->Window;
	}

	GraphicsContext &Layer::GetGraphicsContext() const
	{
		HZ_ASSERT_ATTACHED();
		return context->Window->GetGraphicsContext();
	}

	const Input &Layer::GetInput() const
	{
		return input;
	}

	Input &Layer::GetInput()
	{
		return input;
	}

	void Layer::CloseApplication()
	{
		HZ_ASSERT_ATTACHED();
		context->Settings.Running = false;
	}

	void Layer::EnableGuiRender(bool guiRenderingEnabled)
	{
		HZ_ASSERT_ATTACHED();
		context->Settings.GuiRenderingEnabled = guiRenderingEnabled;
	}

	bool Layer::IsGuiKeyboardFilterEnabled() const
	{
		HZ_ASSERT_ATTACHED();
		return context->Settings.GuiKeyboardFilterEnabled;
	}

	void Layer::EnableGuiKeyboardFilter(bool guiKeyboardFilterEnabled)
	{
		HZ_ASSERT_ATTACHED();
		context->Settings.GuiKeyboardFilterEnabled = guiKeyboardFilterEnabled;
	}

	bool Layer::IsGuiMouseFilterEnabled() const
	{
		HZ_ASSERT_ATTACHED();
		return context->Settings.GuiMouseFilterEnabled;
	}

	void Layer::EnableGuiMouseFilter(bool guiMouseFilterEnabled)
	{
		HZ_ASSERT_ATTACHED();
		context->Settings.GuiMouseFilterEnabled = guiMouseFilterEnabled;
	}

	void Layer::Attach(ApplicationContext &context)
	{
		this->context = &context;
	}

	void Layer::Detach()
	{
		context = nullptr;
	}

	void Layer::OnAttach()
	{
	}

	void Layer::OnDetach()
	{
	}

	void Layer::OnEvent(Event &e)
	{
	}

	void Layer::OnUpdate()
	{
	}

	void Layer::OnGui()
	{
	}
}
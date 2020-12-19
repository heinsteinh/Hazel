#pragma once

#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"
#include "Hazel/Core/Events/KeyPressEvent.h"
#include "Hazel/Core/Events/KeyReleaseEvent.h"
#include "Hazel/Core/Events/KeyTypeEvent.h"
#include "Hazel/Core/Events/MouseButtonPressEvent.h"
#include "Hazel/Core/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Core/Events/MouseMoveEvent.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"
#include "Hazel/Core/Input/InputManager.h"
#include "Hazel/Core/Exceptions/AssertionException.h"
#include "ApplicationContext.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(context, "The layer is not attached to a running application")

namespace Hazel
{
	class BaseLayer
	{
	private:
		std::string name;
		Input input;
		ApplicationContext *context = nullptr;

	public:
		BaseLayer(const std::string &name)
			: name(name)
		{
		}

		virtual ~BaseLayer() = default;

		const std::string &GetName() const
		{
			return name;
		}

		void Attach(ApplicationContext &context)
		{
			this->context = &context;
		}

		void Detach()
		{
			context = nullptr;
		}

		const Input &GetInput() const
		{
			return input;
		}

		Input &GetInput()
		{
			return input;
		}

		float GetDeltaTime() const
		{
			HZ_ASSERT_ATTACHED();
			return context->DeltaTime;
		}

		void CloseApplication()
		{
			HZ_ASSERT_ATTACHED();
			context->Settings.Running = false;
		}

		void EnableGuiRender(bool guiRenderingEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->Settings.GuiRenderingEnabled = guiRenderingEnabled;
		}

		bool IsGuiKeyboardFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->Settings.GuiKeyboardFilterEnabled;
		}

		void EnableGuiKeyboardFilter(bool guiKeyboardFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->Settings.GuiKeyboardFilterEnabled = guiKeyboardFilterEnabled;
		}

		bool IsGuiMouseFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->Settings.GuiMouseFilterEnabled;
		}

		void EnableGuiMouseFilter(bool guiMouseFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->Settings.GuiMouseFilterEnabled = guiMouseFilterEnabled;
		}

		GraphicsApi &GetGraphicsApi() const
		{
			HZ_ASSERT_ATTACHED();
			return *context->GraphicsApi;
		}

		Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return *context->Window;
		}

		GraphicsContext &GetGraphicsContext() const
		{
			HZ_ASSERT_ATTACHED();
			return context->Window->GetGraphicsContext();
		}
	};
}

#undef HZ_ASSERT_ATTACHED
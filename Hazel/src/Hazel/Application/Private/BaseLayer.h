#pragma once

#include "Hazel/Events/WindowCloseEvent.h"
#include "Hazel/Events/WindowResizeEvent.h"
#include "Hazel/Events/KeyPressEvent.h"
#include "Hazel/Events/KeyReleaseEvent.h"
#include "Hazel/Events/KeyTypeEvent.h"
#include "Hazel/Events/MouseButtonPressEvent.h"
#include "Hazel/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Events/MouseMoveEvent.h"
#include "Hazel/Events/MouseScrollEvent.h"
#include "Hazel/Input/InputManager.h"
#include "Hazel/Exceptions/AssertionException.h"
#include "LayerContext.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(context, "The layer is not attached to a running application")

namespace Hazel
{
	class BaseLayer
	{
	private:
		std::string name;
		Input input;
		LayerContext *context = nullptr;

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

		void Attach(LayerContext *context)
		{
			this->context = context;
		}

		void Detach()
		{
			Attach(nullptr);
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
			return context->GetDeltaTime();
		}

		void Quit()
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().Running = false;
		}

		void EnableGuiRender(bool guiRenderingEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().GuiRenderingEnabled = guiRenderingEnabled;
		}

		bool IsGuiKeyboardFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetSettings().GuiKeyboardFilterEnabled;
		}

		void EnableGuiKeyboardFilter(bool guiKeyboardFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().GuiKeyboardFilterEnabled = guiKeyboardFilterEnabled;
		}

		bool IsGuiMouseFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetSettings().GuiMouseFilterEnabled;
		}

		void EnableGuiMouseFilter(bool guiMouseFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().GuiMouseFilterEnabled = guiMouseFilterEnabled;
		}

		Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetWindow();
		}

		GraphicsContext &GetGraphicsContext() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetWindow().GetGraphicsContext();
		}
	};
}

#undef HZ_ASSERT_ATTACHED
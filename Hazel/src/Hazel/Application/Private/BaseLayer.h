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

		void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().ImGuiRenderEnabled = imGuiRenderEnabled;
		}

		bool IsImGuiKeyboardFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetSettings().ImGuiKeyboardFilterEnabled;
		}

		void EnableImGuiKeyboardFilter(bool imGuiKeyboardFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().ImGuiKeyboardFilterEnabled = imGuiKeyboardFilterEnabled;
		}

		bool IsImGuiMouseFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetSettings().ImGuiMouseFilterEnabled;
		}

		void EnableImGuiMouseFilter(bool imGuiMouseFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().ImGuiMouseFilterEnabled = imGuiMouseFilterEnabled;
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
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
#include "Hazel/Input/InputUpdater.h"
#include "Hazel/Exceptions/AssertionException.h"
#include "Private/LayerContext.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(context, "The layer is not attached to a running application")

namespace Hazel
{
	class Layer
	{
	private:
		std::string name;
		Input input;
		LayerContext *context = nullptr;

	public:
		Layer(const std::string &name = "Unknown")
			: name(name)
		{
		}

		virtual ~Layer() = default;

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

		void UpdateInput(Event &e)
		{
			InputUpdater::UpdateInput(input, e);
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

		virtual void OnAttach()
		{
		}

		virtual void OnDetach()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnImGuiRender()
		{
		}
	};
}

#undef HZ_ASSERT_ATTACHED
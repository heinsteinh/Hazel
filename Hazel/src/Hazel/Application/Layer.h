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
#include "Helpers/LayerContext.h"

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

		const std::string &GetName() const
		{
			return name;
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

		bool IsImGuiEventFilterEnabled() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetSettings().ImGuiEventFilterEnabled;
		}

		void EnableImGuiEventFilter(bool imGuiEventFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->GetSettings().ImGuiEventFilterEnabled = imGuiEventFilterEnabled;
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

		const Input &GetInput() const
		{
			return input;
		}

		Input &GetInput()
		{
			return input;
		}

		void SetContext(LayerContext &context)
		{
			this->context = &context;
		}

		void UpdateInput(Event &e)
		{
			InputUpdater::UpdateInput(input, e);
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

		virtual void OnUpdate(float deltaTime)
		{
		}

		virtual void OnImGuiRender()
		{
		}
	};
}

#undef HZ_ASSERT_ATTACHED
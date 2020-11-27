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
			context->SetRunning(false);
		}

		void EnableImGuiRender(bool renderImGui)
		{
			HZ_ASSERT_ATTACHED();
			context->EnableImGuiRender(renderImGui);
		}

		void EnableImGuiEventFilter(bool imGuiEventFilterEnabled)
		{
			HZ_ASSERT_ATTACHED();
			context->EnableImGuiEventFilter(imGuiEventFilterEnabled);
		}

		Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetWindow();
		}

		GraphicsContext &GetGraphicsContext() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetGraphicsContext();
		}

		const Input &GetInput() const
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
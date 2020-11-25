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
		inline Layer(const std::string &name = "Unknown")
			: name(name)
		{
		}

		inline const std::string &GetName() const
		{
			return name;
		}

		inline void Quit()
		{
			HZ_ASSERT_ATTACHED();
			context->SetRunning(false);
		}

		inline void EnableImGuiRender(bool renderImGui)
		{
			HZ_ASSERT_ATTACHED();
			context->EnableImGuiRender(renderImGui);
		}

		inline Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetWindow();
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			HZ_ASSERT_ATTACHED();
			return context->GetGraphicsContext();
		}

		inline const Input &GetInput() const
		{
			return input;
		}

		inline void SetContext(LayerContext &context)
		{
			this->context = &context;
		}

		inline void UpdateInput(Event &e)
		{
			InputUpdater::UpdateInput(input, e);
		}

		inline virtual void OnAttach()
		{
		}

		inline virtual void OnDetach()
		{
		}

		inline virtual void OnEvent(Event &e)
		{
		}

		inline virtual void OnUpdate(float deltaTime)
		{
		}

		inline virtual void OnImGuiRender()
		{
		}
	};
}

#undef HZ_ASSERT_ATTACHED
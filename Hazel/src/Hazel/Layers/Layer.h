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
#include "Hazel/Layers/LayersContext.h"
#include "Hazel/Input/InputUpdater.h"

namespace Hazel
{
	class Layer
	{
	private:
		std::string name;
		Input input;
		LayersContext *context = nullptr;

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
			context->SetRunning(false);
		}

		inline void EnableImGuiRender(bool renderImGui)
		{
			context->EnableImGuiRender(renderImGui);
		}

		inline Window &GetWindow() const
		{
			return context->GetWindow();
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			return context->GetGraphicsContext();
		}

		inline const Input &GetInput() const
		{
			return input;
		}

		inline void SetContext(LayersContext &context)
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
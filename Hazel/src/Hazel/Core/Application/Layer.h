#pragma once

#include <string>

#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"
#include "Hazel/Core/Window/Window.h"
#include "Hazel/Core/Input/Input.h"
#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"
#include "Hazel/Core/Events/KeyPressEvent.h"
#include "Hazel/Core/Events/KeyReleaseEvent.h"
#include "Hazel/Core/Events/KeyTypeEvent.h"
#include "Hazel/Core/Events/MouseButtonPressEvent.h"
#include "Hazel/Core/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Core/Events/MouseMoveEvent.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"
#include "Private/ApplicationContext.h"

namespace Hazel
{
	class Layer
	{
	private:
		std::string name;
		Input input;
		ApplicationContext *context = nullptr;

	public:
		Layer(const std::string &name)
			: name(name)
		{
		}
		virtual ~Layer() = default;

		const std::string &GetName() const
		{
			return name;
		}

		float GetDeltaTime() const
		{
			return context->DeltaTime;
		}

		GraphicsApi &GetGraphicsApi() const
		{
			return *context->GraphicsApi;
		}

		Window &GetWindow() const
		{
			return *context->Window;
		}

		GraphicsContext &GetGraphicsContext() const
		{
			return context->Window->GetGraphicsContext();
		}

		const Input &GetInput() const
		{
			return input;
		}

		Input &GetInput()
		{
			return input;
		}

		void CloseApplication()
		{
			context->Settings.Running = false;
		}

		void EnableGuiRender(bool guiRenderingEnabled)
		{
			context->Settings.GuiRenderingEnabled = guiRenderingEnabled;
		}

		bool IsGuiKeyboardFilterEnabled() const
		{
			return context->Settings.GuiKeyboardFilterEnabled;
		}

		void EnableGuiKeyboardFilter(bool guiKeyboardFilterEnabled)
		{
			context->Settings.GuiKeyboardFilterEnabled = guiKeyboardFilterEnabled;
		}

		bool IsGuiMouseFilterEnabled() const
		{
			return context->Settings.GuiMouseFilterEnabled;
		}

		void EnableGuiMouseFilter(bool guiMouseFilterEnabled)
		{
			context->Settings.GuiMouseFilterEnabled = guiMouseFilterEnabled;
		}

		void Attach(ApplicationContext &context)
		{
			this->context = &context;
		}

		void Detach()
		{
			context = nullptr;
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

		virtual void OnGui()
		{
		}
	};
}
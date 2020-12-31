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
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	struct ApplicationContext;

	class Layer
	{
	private:
		std::string name;
		Input input;
		ApplicationContext *context = nullptr;

	public:
		Layer(const std::string &name);
		virtual ~Layer() = default;

		const std::string &GetName() const;
		float GetDeltaTime() const;
		GraphicsApi &GetGraphicsApi() const;
		Window &GetWindow() const;
		GraphicsContext &GetGraphicsContext() const;
		const Input &GetInput() const;
		Input &GetInput();
		void CloseApplication();
		void EnableGuiRender(bool guiRenderingEnabled);
		bool IsGuiKeyboardFilterEnabled() const;
		void EnableGuiKeyboardFilter(bool guiKeyboardFilterEnabled);
		bool IsGuiMouseFilterEnabled() const;
		void EnableGuiMouseFilter(bool guiMouseFilterEnabled);
		void Attach(ApplicationContext &context);
		void Detach();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnEvent(Event &e);
		virtual void OnUpdate();
		virtual void OnGui();
	};
}
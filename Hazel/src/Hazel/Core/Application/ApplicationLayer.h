#pragma once

#include <string>

#include "Hazel/Core/Input/Input.h"
#include "Hazel/Core/Events/Event.h"
#include "ApplicationView.h"

namespace Hazel
{
	class ApplicationLayer
	{
	private:
		std::string name;
		Input input;
		ApplicationView application;

	public:
		ApplicationLayer(const std::string &name)
			: name(name)
		{
		}

		virtual ~ApplicationLayer() = default;

		const std::string &GetName() const
		{
			return name;
		}

		const Input &GetInput() const
		{
			return input;
		}

		Input &GetInput()
		{
			return input;
		}

		ApplicationView GetApplication() const
		{
			return application;
		}

		void Attach(ApplicationView application)
		{
			this->application = application;
			OnAttach();
		}

		void Detach()
		{
			OnDetach();
			application = {};
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
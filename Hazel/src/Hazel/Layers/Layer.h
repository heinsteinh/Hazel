#pragma once

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	class Layer : public EventListener
	{
	public:
		virtual ~Layer() = default;

		inline virtual const std::string &GetName() const
		{
			static const std::string defaultName = "Unknown";
			return defaultName;
		}

		inline virtual void OnAttach()
		{
		}

		inline virtual void OnDetach()
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
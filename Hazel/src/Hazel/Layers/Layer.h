#pragma once

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	class Layer : public EventListener
	{
	private:
		static inline const std::string defaultName = "Unknown";

	public:
		inline virtual const std::string &GetName() const
		{
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
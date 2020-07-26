#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class KeyTypeEvent : public Event
	{
	private:
		unsigned int key = 0;

	public:
		constexpr KeyTypeEvent(unsigned int key)
			: Event(EventType::KeyType, EventCategory::Input | EventCategory::Keyboard),
			key(key)
		{
		}

		constexpr unsigned int GetKey() const
		{
			return key;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << key).str();
		}
	};
}
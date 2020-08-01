#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class KeyTypeEvent : public Event
	{
	private:
		uint32_t key = 0;

	public:
		constexpr KeyTypeEvent(uint32_t key)
			: Event(EventType::KeyType, EventCategory::Input | EventCategory::Keyboard),
			key(key)
		{
		}

		constexpr uint32_t GetKey() const
		{
			return key;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << key).str();
		}
	};
}
#pragma once

#include "spdlog/fmt/ostr.h"

#include "EventType.h"
#include "EventCategory.h"

namespace Hazel
{
	class EventListener;

	class Event
	{
	private:
		EventType type = EventType::Unknown;
		EventCategory categories = EventCategory::None;
		bool handled = false;

	public:
		constexpr Event(EventType type, EventCategory categories)
			: type(type),
			categories(categories)
		{
		}

		virtual ~Event() = default;

		Event(const Event &other) = delete;
		Event &operator=(const Event &other) = delete;

		constexpr EventType GetType() const
		{
			return type;
		}

		constexpr bool IsInCategory(EventCategory category) const
		{
			return categories & category;
		}

		constexpr bool IsHandled() const
		{
			return handled;
		}

		constexpr void Discard()
		{
			handled = true;
		}

		inline const char *GetName() const
		{
			return typeid(*this).name() + 13;
		}

		inline virtual std::string ToString() const
		{
			return GetName();
		}
	};
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Event &e)
{
	return stream << e.ToString();
}
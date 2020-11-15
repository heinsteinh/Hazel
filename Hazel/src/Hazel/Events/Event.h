#pragma once

#include "spdlog/fmt/ostr.h"

#include "Hazel/Utils/FunctorTraits.h"
#include "EventType.h"
#include "EventCategory.h"

namespace Hazel
{
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

		template<typename FunctorType>
		void Dispatch(const FunctorType &functor)
		{
			using Traits = FunctorTraits<FunctorType>;
			static_assert(Traits::ArgCount == 1, "Functor must take only one argument.");
			using EventType = std::decay_t<Traits::ArgType<0>>;
			static_assert(std::is_convertible_v<EventType &, Event &>, "Functor argument must be an event.");
			if (!handled && type == EventType::Type)
			{
				functor(static_cast<EventType &>(*this));
			}
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
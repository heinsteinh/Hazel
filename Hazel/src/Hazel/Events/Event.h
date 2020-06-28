#pragma once

#include "spdlog/fmt/ostr.h"

namespace Hazel
{
	class EventListener;

	class Event
	{
	private:
		bool handled = false;

	public:
		Event() = default;
		virtual ~Event() = default;

		Event(const Event &other) = delete;
		Event &operator=(const Event &other) = delete;

		inline const char *GetName() const
		{
			return typeid(*this).name() + 13;
		}

		constexpr bool IsHandled() const
		{
			return handled;
		}

		constexpr void Discard()
		{
			handled = true;
		}

		void Dispatch(EventListener *listener);

		virtual std::string ToString() const;

	protected:
		virtual void DispatchEvent(EventListener &listener) = 0;
	};
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Event &e)
{
	return stream << e.ToString();
}
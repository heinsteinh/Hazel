#include "Event.h"

#include "EventListener.h"

namespace Hazel
{
	void Event::Dispatch(EventListener *listener)
	{
		if (listener && !handled)
		{
			listener->OnEvent(*this);
			if (!handled)
			{
				DispatchEvent(*listener);
			}
		}
	}

	std::string Event::ToString() const
	{
		return GetName();
	}
}
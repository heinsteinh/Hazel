#pragma once

#include "ApplicationEvent.h"

namespace Hazel
{
	class WindowCloseEvent : public ApplicationEvent
	{
	protected:
		virtual void DispatchApplicationEvent(EventListener &listener) override;
	};
}
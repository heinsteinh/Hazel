#pragma once

#include "BaseNativeScript.h"

namespace Hazel
{
	class NativeScript : public BaseNativeScript
	{
	public:
		virtual void OnCreate()
		{
		}

		virtual void OnDestroy()
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}
	};
}
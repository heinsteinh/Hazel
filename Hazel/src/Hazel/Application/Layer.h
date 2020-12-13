#pragma once

#include "Private/BaseLayer.h"

namespace Hazel
{
	class Layer : public BaseLayer
	{
	public:
		Layer(const std::string &name = "Unknown")
			: BaseLayer(name)
		{
		}

		virtual void OnAttach()
		{
		}

		virtual void OnDetach()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnGui()
		{
		}
	};
}
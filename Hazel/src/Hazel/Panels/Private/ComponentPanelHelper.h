#pragma once

namespace Hazel
{
	class ComponentPanelHelper
	{
	public:
		template<typename ComponentType>
		static void *GetComponentId()
		{
			return reinterpret_cast<void *>(typeid(ComponentType).hash_code());
		}
	};
}
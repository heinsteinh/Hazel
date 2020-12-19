#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Entity.h"

namespace Hazel
{
	class EntityNodePopup
	{
	private:
		bool destroyEntity = false;

	public:
		bool WantDestroyEntity() const
		{
			return destroyEntity;
		}

		void Draw(Entity entity)
		{
			destroyEntity = false;
			if (ImGui::BeginPopupContextItem())
			{
				if (ImGui::MenuItem("Destroy Entity"))
				{
					destroyEntity = true;
				}
				ImGui::EndPopup();
			}
		}
	};
}
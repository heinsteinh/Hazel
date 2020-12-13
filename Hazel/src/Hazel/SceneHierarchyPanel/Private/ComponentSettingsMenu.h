#pragma once

#include "imgui.h"

namespace Hazel
{
	class ComponentSettingsMenu
	{
	private:
		static constexpr const char *id = "ComponentSettings";

		bool removeComponent = false;

	public:
		bool WantRemoveComponent() const
		{
			return removeComponent;
		}

		void Draw()
		{
			removeComponent = false;
			if (ImGui::Button("+"))
			{
				ImGui::OpenPopup(id);
			}
			DrawPopup();
		}

	private:
		void DrawPopup()
		{
			if (ImGui::BeginPopup(id))
			{
				if (ImGui::MenuItem("Remove Component"))
				{
					removeComponent = true;
				}
				ImGui::EndPopup();
			}
		}
	};
}
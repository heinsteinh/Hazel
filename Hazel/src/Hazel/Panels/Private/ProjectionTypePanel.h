#pragma once

#include "imgui.h"

#include "Hazel/Geometry/ProjectionType.h"

namespace Hazel
{
	class ProjectionTypePanel
	{
	private:
		static constexpr std::array<const char *, static_cast<size_t>(ProjectionType::Count)> projectionLabels = {
			"Orthographic",
			"Perspective"
		};

	public:
		bool Draw(ProjectionType &projectionType)
		{
			bool changed = false;
			auto labelIndex = static_cast<size_t>(projectionType);
			if (ImGui::BeginCombo("Projection Type", projectionLabels[labelIndex]))
			{
				for (size_t i = 0; i < projectionLabels.size(); i++)
				{
					bool selected = i == labelIndex;
					if (ImGui::Selectable(projectionLabels[i], &selected))
					{
						projectionType = static_cast<ProjectionType>(i);
						changed = true;
					}
					if (selected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			return changed;
		}
	};
}
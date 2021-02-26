#pragma once

#include <vector>
#include <string>

#include "imgui.h"

#include "Hazel/Core/Geometry/ProjectionType.h"
#include "Hazel/Editor/Widgets/ComboText.h"

namespace Hazel
{
	class ProjectionTypeCombo
	{
	private:
		static inline std::vector<std::string> labels = {
			"Orthographic",
			"Perspective"
		};

	public:
		static bool Draw(ProjectionType &projectionType)
		{
			auto selectedIndex = static_cast<size_t>(projectionType);
			auto changed = ComboText::Draw("Projection Type", labels, selectedIndex);
			projectionType = static_cast<ProjectionType>(selectedIndex);
			return changed;
		}
	};
}
#pragma once

#include <vector>
#include <string>

#include "Hazel/Core/Geometry/ProjectionType.h"
#include "Hazel/Core/Utils/EnumMap.h"
#include "Hazel/Editor/Widgets/ComboBox.h"

namespace Hazel
{
	class ProjectionTypeWidget
	{
	private:
		static inline const EnumMap<ProjectionType, std::string> labels = {
			{ProjectionType::Orthographic, "Orthographic"},
			{ProjectionType::Perspective, "Perspective"}
		};

	public:
		static bool Draw(ProjectionType &projectionType)
		{
			bool changed = false;
			if (ComboBox::Begin("Projection Type", labels[projectionType].c_str()))
			{
				labels.ForEach([&](ProjectionType currentProjection, const std::string &label)
				{
					bool selected = currentProjection == projectionType;
					if (ComboBox::DrawItem(label.c_str(), selected))
					{
						projectionType = currentProjection;
						changed = true;
					}
				});
				ComboBox::End();
			}
			return changed;
		}
	};
}
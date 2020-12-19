#pragma once

#include "Hazel/Scene/Components/CameraComponent.h"

#include "Hazel/Editor/Widgets/ProjectionTypePanel.h"
#include "Hazel/Editor/Widgets/OrthographicProjectionPanel.h"
#include "Hazel/Editor/Widgets/PerspectiveProjectionPanel.h"

namespace Hazel
{
	class CameraPanel
	{
	private:
		static constexpr std::array<const char *, static_cast<size_t>(ProjectionType::Count)> projectionLabels = {
			"Orthographic",
			"Perspective"
		};

		ProjectionTypePanel projectionTypePanel;
		OrthographicProjectionPanel orthographicProjectionPanel;
		PerspectiveProjectionPanel perspectiveProjectionPanel;

	public:
		void Draw(CameraComponent &camera)
		{
			Draw(camera.Camera);
		}

		void Draw(Camera &camera)
		{
			DrawProjectionType(camera);
			switch (camera.GetProjectionType())
			{
			case ProjectionType::Orthographic:
				DrawOrthographic(camera);
				break;
			case ProjectionType::Perspective:
				DrawPerspective(camera);
			}
		}

		void DrawProjectionType(Camera &camera)
		{
			auto projectionType = camera.GetProjectionType();
			if (projectionTypePanel.Draw(projectionType))
			{
				camera.SetProjectionType(projectionType);
			}
		}

		void DrawOrthographic(Camera &camera)
		{
			auto projection = camera.GetOrthographicProjection();
			if (orthographicProjectionPanel.Draw(projection))
			{
				camera.SetOrthographicProjection(projection);
			}
		}

		void DrawPerspective(Camera &camera)
		{
			auto projection = camera.GetPerspectiveProjection();
			if (perspectiveProjectionPanel.Draw(projection))
			{
				camera.SetPerspectiveProjection(projection);
			}
		}
	};
}
#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class CreateEntityPopup
	{
	public:
		static void Draw(Scene &scene)
		{
			PopupSettings settings;
			settings.MouseButton = MouseButton::Right;
			settings.OpenOverItem = false;
			if (Popup::BeginOnWindow(nullptr, settings))
			{
				if (Popup::DrawItem("Create Empty Entity"))
				{
					auto newEntity = scene.CreateEntity();
					newEntity.AddComponent<TagComponent>("New Entity");
					newEntity.AddComponent<TransformComponent>();
				}
				Popup::End();
			}
		}
	};
}
#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"

namespace Hazel
{
	class AddComponentMenu
	{
	private:
		static constexpr const char *id = "AddComponent";

	public:
		void Draw(const char *label, Entity entity)
		{
			if (ImGui::Button(label))
			{
				ImGui::OpenPopup(id);
			}
			DrawPopup(id, entity);
		}

	private:
		void DrawPopup(const char *id, Entity entity)
		{
			if (ImGui::BeginPopup(id))
			{
				DrawItem<TransformComponent>("Transform", entity);
				DrawItem<CameraComponent>("Camera", entity);
				DrawItem<SpriteComponent>("Sprite", entity);
				ImGui::EndPopup();
			}
		}

		template<typename ComponentType>
		void DrawItem(const char *label, Entity entity)
		{
			if (!entity.HasComponent<ComponentType>() && ImGui::MenuItem(label))
			{
				entity.AddComponent<ComponentType>();
				ImGui::CloseCurrentPopup();
			}
		}
	};
}
#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class AddComponentPopup
	{
	private:
		static constexpr const char *id = "AddComponent";

	public:
		static void Open()
		{
			Popup::Open(id);
		}

		static bool Draw(Entity entity)
		{
			bool changed = false;
			if (Popup::Begin(id))
			{
				changed |= DrawItem<CameraComponent>("Camera", entity);
				changed |= DrawItem<SpriteComponent>("Sprite", entity);
				changed |= DrawItem<ParticleComponent>("Particle", entity);
				Popup::End();
			}
			return changed;
		}

	private:
		template<typename ComponentType>
		static bool DrawItem(const char *label, Entity entity)
		{
			if (Popup::DrawItem(label) && !entity.HasComponent<ComponentType>())
			{
				entity.AddComponent<ComponentType>();
				Popup::Close();
				return true;
			}
			return false;
		}
	};
}
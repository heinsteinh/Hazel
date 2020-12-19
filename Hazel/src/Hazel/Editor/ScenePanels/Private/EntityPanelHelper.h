#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"

namespace Hazel
{
	class EntityPanelHelper
	{
	public:
		static void *GetEntityId(Entity entity)
		{
			return reinterpret_cast<void *>(static_cast<size_t>(entity.GetId()));
		}

		static ImGuiTreeNodeFlags GetFlags(Entity entity, Entity selectedEntity)
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
			if (entity == selectedEntity)
			{
				flags |= ImGuiTreeNodeFlags_Selected;
			}
			return flags;
		}

		static const char *GetTag(Entity entity)
		{
			auto tag = entity.TryGetComponent<TagComponent>();
			return tag ? tag->Name.c_str() : "Unknown";
		}
	};
}
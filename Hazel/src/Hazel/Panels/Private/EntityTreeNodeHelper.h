#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity.h"
#include "Hazel/Components/TagComponent.h"

namespace Hazel
{
	class EntityTreeNodeHelper
	{
	public:
		static void *GetId(Entity entity)
		{
			return reinterpret_cast<void *>(static_cast<size_t>(entity.GetId()));
		}

		static ImGuiTreeNodeFlags GetFlags(Entity entity, Entity selectedEntity)
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow;
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
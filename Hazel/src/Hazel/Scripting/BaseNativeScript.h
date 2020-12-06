#pragma once

#include "Hazel/Scene/Entity.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(layer, "The script is not attached to a valid entity")

namespace Hazel
{
	class BaseNativeScript
	{
	private:
		Entity entity;
		Layer *layer = nullptr;

	public:
		virtual ~BaseNativeScript() = default;

		void Attach(Entity entity)
		{
			this->entity = entity;
			layer = entity.GetSceneContext().Layer;
		}

		void Detach()
		{
			entity = {};
			layer = nullptr;
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			HZ_ASSERT_ATTACHED();
			return entity.GetComponent<ComponentType>();
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			HZ_ASSERT_ATTACHED();
			return entity.TryGetComponent<ComponentType>();
		}

		float GetDeltaTime() const
		{
			HZ_ASSERT_ATTACHED();
			return layer->GetDeltaTime();
		}

		const Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return layer->GetWindow();
		}

		const Input &GetInput() const
		{
			HZ_ASSERT_ATTACHED();
			return layer->GetInput();
		}

		const CameraProjection &GetCameraProjection() const
		{
			HZ_ASSERT_ATTACHED();
			return entity.GetSceneContext().CameraProjection;
		}
	};
}

#undef HZ_ASSERT_ATTACHED
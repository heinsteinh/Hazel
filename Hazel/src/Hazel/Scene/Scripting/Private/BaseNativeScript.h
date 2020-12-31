#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

#define HZ_ASSERT_ATTACHED() HZ_ASSERT(entity.IsValid(), "The script is not attached to a valid entity")

namespace Hazel
{
	class BaseNativeScript
	{
	private:
		Entity entity;

	public:
		virtual ~BaseNativeScript() = default;

		void Attach(Entity entity)
		{
			this->entity = entity;
		}

		void Detach()
		{
			entity = {};
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
			return entity.GetSceneContext().Layer->GetDeltaTime();
		}

		const Window &GetWindow() const
		{
			HZ_ASSERT_ATTACHED();
			return entity.GetSceneContext().Layer->GetWindow();
		}

		const Input &GetInput() const
		{
			HZ_ASSERT_ATTACHED();
			return entity.GetSceneContext().Layer->GetInput();
		}

		const Camera &GetCamera() const
		{
			HZ_ASSERT_ATTACHED();
			return entity.GetSceneContext().Camera;
		}
	};
}

#undef HZ_ASSERT_ATTACHED
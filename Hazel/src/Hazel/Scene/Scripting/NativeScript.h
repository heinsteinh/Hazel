#pragma once

#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	class NativeScript
	{
	private:
		Entity entity;

	public:
		virtual ~NativeScript() = default;

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
			return entity.GetComponent<ComponentType>();
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			return entity.TryGetComponent<ComponentType>();
		}

		float GetDeltaTime() const
		{
			return entity.GetLayer().GetDeltaTime();
		}

		const Window &GetWindow() const
		{
			return entity.GetLayer().GetWindow();
		}

		const Input &GetInput() const
		{
			return entity.GetLayer().GetInput();
		}

		const Camera &GetCamera() const
		{
			return entity.GetCamera();
		}

		virtual void OnCreate()
		{
		}

		virtual void OnDestroy()
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}

		virtual void OnGui()
		{
		}
	};
}
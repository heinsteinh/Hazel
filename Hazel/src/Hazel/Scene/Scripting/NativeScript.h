#pragma once

#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	class NativeScript
	{
	private:
		std::string name;
		Entity entity;

	public:
		virtual ~NativeScript() = default;

		const std::string &GetName() const
		{
			return name;
		}

		void SetName(const std::string &name)
		{
			this->name = name;
		}

		void Attach(Entity entity)
		{
			this->entity = entity;
		}

		void Detach()
		{
			entity = {};
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

		Transform &GetTransform() const
		{
			return entity.GetTransform();
		}

		template<typename ComponentType>
		ComponentType &GetComponent() const
		{
			return entity.GetComponent<ComponentType>();
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent() const
		{
			return entity.TryGetComponent<ComponentType>();
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
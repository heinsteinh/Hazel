#include "SceneManager.h"

#include "SceneCamera.h"
#include "CameraManager.h"
#include "NativeScriptManager.h"
#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void SceneManager::OnUpdate(SceneContext &context)
	{
		NativeScriptManager::OnUpdate(context);
		renderer.OnUpdate(context);
	}

	void SceneManager::OnViewportResize(SceneContext &context, const glm::vec2 &viewport)
	{
		CameraManager::OnViewportResize(context, viewport);
	}

	void SceneManager::OnEvent(SceneContext &context, Event &e)
	{
		NativeScriptManager::OnEvent(context, e);
	}
}
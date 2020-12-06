#include "SceneManager.h"

#include "CameraManager.h"
#include "NativeScriptManager.h"
#include "ParticleManager.h"

namespace Hazel
{
	void SceneManager::OnUpdate(SceneContext &context)
	{
		CameraManager::OnUpdate(context);
		NativeScriptManager::OnUpdate(context);
		ParticleManager::OnUpdate(context);
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

	void SceneManager::OnImGuiRender(SceneContext &context)
	{
		NativeScriptManager::OnImGuiRender(context);
	}
}
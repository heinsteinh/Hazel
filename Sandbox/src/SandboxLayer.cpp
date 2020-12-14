#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer()
		: Layer("Sandbox")
	{
	}

	void SandboxLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		Hazel::BatchInfo batchInfo;
		batchInfo.MaxIndexCount = 10000;
		batchInfo.MaxVertexCount = 40000;
		batchInfo.MaxTextureSlotCount = graphicsContext.GetMaxTextureSlotCount();
		renderer = std::make_shared<Hazel::Renderer2D>(graphicsContext, batchInfo);

		spriteSheet = Hazel::TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");

		Hazel::SceneInfo sceneInfo;
		sceneInfo.Layer = this;
		sceneInfo.Renderer = renderer.get();
		scene = std::make_shared<Hazel::Scene>(sceneInfo);

		square = scene->CreateEntity();
		square.AddComponent<Hazel::SpriteComponent>(glm::vec4(1.0f), spriteSheet);
		square.AddComponent<Hazel::TransformComponent>().Transform.Scale.x = spriteSheet.GetRegion().GetAspectRatio();

		camera1 = scene->CreateEntity();
		camera1.AddComponent<Hazel::TransformComponent>();
		camera1.AddComponent<Hazel::CameraComponent>();

		scene->SetMainCamera(camera1);

		camera2 = scene->CreateEntity();
		camera2.AddComponent<Hazel::TransformComponent>().Transform.Translation.x = 1.0f;
		camera2.AddComponent<Hazel::CameraComponent>();

		auto particleEmitter = scene->CreateEntity();
		particleEmitter.AddComponent<Hazel::ParticleSourceComponent>();

		scene->OnViewportResize(Hazel::Rectangle::FromBottomLeftAndSize({0.0f, 0.0f}, GetWindow().GetSize()));
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate()
	{
		scene->OnUpdate();
		scene->OnRender();
	}

	void SandboxLayer::OnGui()
	{
		scene->OnGui();
	}

	void SandboxLayer::OnEvent(Hazel::Event &e)
	{
		e.Dispatch([this](Hazel::WindowResizeEvent &e)
		{
			scene->OnViewportResize(Hazel::Rectangle::FromBottomLeftAndSize({0.0f, 0.0f}, e.GetSize()));
		});
		scene->OnEvent(e);
	}
}
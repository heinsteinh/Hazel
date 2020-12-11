#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer()
		: Layer("Sandbox")
	{
	}

	void SandboxLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		rendererInfo.MaxIndexCount = 10000;
		rendererInfo.MaxVertexCount = 40000;
		rendererInfo.MaxTextureSlotCount = graphicsContext.GetMaxTextureSlotCount();
		renderer = std::make_shared<Hazel::Renderer2D>(graphicsContext, rendererInfo);

		spriteSheet = Hazel::TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");
		region = spriteSheet.GetRegion();

		Hazel::SceneInfo sceneInfo;
		sceneInfo.Layer = this;
		sceneInfo.Renderer = renderer.get();
		scene = std::make_shared<Hazel::Scene>(sceneInfo);

		square = scene->CreateEntity();
		square.AddComponent<Hazel::SpriteComponent>();
		square.AddComponent<Hazel::TransformComponent>().Transform.Scale.x = spriteSheet.GetRegion().GetAspectRatio();
		square.AddComponent<Hazel::TextureComponent>(spriteSheet);

		camera1 = scene->CreateEntity();
		camera1.AddComponent<Hazel::TransformComponent>();
		camera1.AddComponent<Hazel::NativeScriptComponent>(std::make_shared<Hazel::CameraControllerScript>());
		camera1.AddComponent<Hazel::CameraComponent>();

		scene->SetMainCamera(camera1);

		camera2 = scene->CreateEntity();
		camera2.AddComponent<Hazel::TransformComponent>().Transform.Translation.x = 1.0f;
		camera2.AddComponent<Hazel::CameraComponent>();

		auto particleEmitter = scene->CreateEntity();
		particleEmitter.AddComponent<Hazel::ParticleSourceComponent>();
		particleEmitter.AddComponent<Hazel::NativeScriptComponent>(std::make_shared<Hazel::ParticleScript>());

		scene->OnViewportResize(Hazel::Rectangle::FromBottomLeftAndSize({0.0f, 0.0f}, GetWindow().GetSize()));
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate()
	{
		Hazel::SubTexture &texture = square.GetComponent<Hazel::TextureComponent>().Texture;
		texture.SetRegion(region);

		scene->OnUpdate();
		scene->OnRender();
	}

	void SandboxLayer::OnImGuiRender()
	{
		scene->OnImGuiRender();

		infoPanel.Draw("Info", *this);

		ImGui::Begin("Camera");
		transformPanel.Draw(camera1.GetComponent<Hazel::TransformComponent>());
		ImGui::End();

		ImGui::Begin("Transform");
		transformPanel.Draw(square.GetComponent<Hazel::TransformComponent>());
		ImGui::End();

		textureRegionPanel.Draw("Texture Coordinates", region, spriteSheet.GetSource()->GetSize());

		rendererInfoPanel.Draw("Renderer Info", rendererInfo, renderer->GetStatistics());
		if (rendererInfoPanel.WantReset())
		{
			renderer = std::make_shared<Hazel::Renderer2D>(GetGraphicsContext(), rendererInfo);
		}
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
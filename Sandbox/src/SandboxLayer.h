#pragma once

#include "Hazel.h"
#include "Hazel/Tests/TestParticle.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:
		float renderTime = 0.0f;
		int maxVertices = 40000;
		int maxIndices = 60000;
		glm::vec2 bottomLeft{0.0f};
		glm::vec2 size{2560.0f, 1664.0f};

		std::shared_ptr<Hazel::Renderer2D> renderer;
		Hazel::Scene scene;
		std::shared_ptr<Hazel::Mesh> squareMesh;
		Hazel::Transform transform;
		Hazel::DrawData drawData;
		Hazel::Entity square;
		Hazel::Entity camera;
		Hazel::SubTexture spriteSheet;
		std::shared_ptr<Hazel::TestParticle> particles;
		Hazel::TransformComponentUI transformUI;

	public:
		SandboxLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
	};
}
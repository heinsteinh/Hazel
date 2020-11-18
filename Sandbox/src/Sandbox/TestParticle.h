#pragma once

#include "Hazel.h"
#include "Hazel/Geometry/ScreenTransform.h"

namespace Sandbox
{
	class TestParticle : public Hazel::Layer
	{
	private:
		Hazel::OrthographicCamera camera;
		Hazel::OrthographicCameraController controller;
		std::shared_ptr<Hazel::Renderer2D> renderer;
		Hazel::ScreenTransform screenTransform;

		float renderTime = 0.0f;
		int nParticles = 5;
		int maxParticles = 1000;

		int maxIndices = 60000;
		int maxVertices = 40000;

		Hazel::ParticleInfo particleInfo;
		Hazel::ParticleInfo defaultInfo;
		Hazel::ParticleSystem particleSystem;

	public:
		TestParticle();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
	};
}
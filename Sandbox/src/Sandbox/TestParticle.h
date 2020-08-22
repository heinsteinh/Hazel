#pragma once

#include "Hazel.h"
#include "Hazel/Geometry/ScreenTransform.h"

namespace Sandbox
{
	class TestParticle : public Hazel::Layer
	{
	private:
		Hazel::WindowProperties &window;
		Hazel::Input &input;
		Hazel::OrthographicCamera camera;
		Hazel::OrthographicCameraController controller;
		Hazel::Renderer2D renderer;
		Hazel::ScreenTransform screenTransform;

		float renderTime = 0.0f;
		int nParticles = 5;
		int maxParticles = 1000;

		int maxIndices = (int)renderer.GetBatchInfo().MaxIndices;
		int maxVertices = (int)renderer.GetBatchInfo().MaxVertices;
		int maxTextures = (int)renderer.GetBatchInfo().MaxTextures;

		Hazel::ParticleInfo particleInfo;
		Hazel::ParticleInfo defaultInfo;
		Hazel::ParticleSystem particleSystem;

	public:
		TestParticle(Hazel::Context &context);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnKeyPressed(Hazel::KeyPressEvent &e) override;
	};
}
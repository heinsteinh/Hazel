#pragma once

#include "Hazel.h"
#include "Hazel/Geometry/ScreenTransform.h"

namespace Sandbox
{
	class TestParticle
	{
	private:
		Hazel::Renderer2D *renderer = nullptr;
		Hazel::ScreenTransform screenTransform;
		const Hazel::Input *input = nullptr;

		int nParticles = 5;
		int maxParticles = 1000;

		Hazel::ParticleInfo particleInfo;
		Hazel::ParticleInfo defaultInfo;
		Hazel::ParticleSystem particleSystem;

	public:
		TestParticle();

		void OnAttach(Hazel::Renderer2D &renderer, Hazel::ScreenTransform screenTransform, const Hazel::Input &input);
		void OnDetach();
		void OnUpdate(float deltaTime);
		void OnImGuiRender();
	};
}
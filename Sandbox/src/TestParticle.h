#pragma once

#include "Hazel.h"

namespace Sandbox
{
	class TestParticle
	{
	private:
		Hazel::Renderer2D *renderer = nullptr;
		const Hazel::OrthographicCamera *camera = nullptr;
		const Hazel::Input *input = nullptr;

		int nParticles = 5;
		int maxParticles = 1000;

		Hazel::ParticleInfo particleInfo;
		Hazel::ParticleInfo defaultInfo;
		Hazel::ParticleSystem particleSystem;

	public:
		TestParticle();

		void OnAttach(Hazel::Renderer2D &renderer, const Hazel::OrthographicCamera &camera, const Hazel::Input &input);
		void OnDetach();
		void OnUpdate(float deltaTime);
		void OnImGuiRender();
	};
}
#pragma once

#include "Test.h"
#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/ParticleSystem/ParticleSystem.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/Input/Input.h"

namespace Hazel
{
	class TestParticle : public Test
	{
	private:
		Renderer2D *renderer = nullptr;
		const OrthographicCamera *camera = nullptr;
		const Input *input = nullptr;

		int nParticles = 5;
		int maxParticles = 1000;

		ParticleInfo particleInfo;
		ParticleInfo defaultInfo;
		ParticleSystem particleSystem;

	public:
		TestParticle(Renderer2D &renderer, const OrthographicCamera &camera, const Input &input);

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnImGuiRender() override;
	};
}
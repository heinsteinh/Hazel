#pragma once

#include "Hazel.h"

namespace Sandbox
{
	class TestParticle : public Hazel::Layer
	{
	private:
		Hazel::ParticleSystem particleSystem;

	public:
		TestParticle();
	};
}
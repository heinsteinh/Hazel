#pragma once

#include "Hazel/Rendering/Particles/ParticleInfo.h"
#include "Hazel/Rendering/Particles/ParticleSource.h"

namespace Hazel
{
	struct ParticleComponent
	{
		ParticleInfo Info;
		ParticleSource Source;
	};
}
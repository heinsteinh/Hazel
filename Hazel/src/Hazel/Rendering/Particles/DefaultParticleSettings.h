#pragma once

#include "ParticleInfo.h"

namespace Hazel
{
	class DefaultParticleSettings
	{
	private:
		static const ParticleInfo particleInfo;

	public:
		static size_t GetMaxParticleCount()
		{
			return 1000;
		}

		static const ParticleInfo &GetParticleInfo()
		{
			return particleInfo;
		}

		static ParticleInfo CreateParticleInfo();
	};
}
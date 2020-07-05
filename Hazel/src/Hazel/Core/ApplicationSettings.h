#pragma once

#include "Hazel/Layers/LayerManager.h"

namespace Hazel
{
	class ApplicationSettings
	{
	private:
		LayerManager &layerManager;

	public:
		constexpr ApplicationSettings(LayerManager &layerManager)
			: layerManager(layerManager)
		{
		}

		inline void ShowImGui(bool show)
		{
			layerManager.ShowImGui(show);
		}
	};
}
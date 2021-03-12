#pragma once

#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "Hazel/Scene/Scene/Scene.h"
#include "SceneParsingException.h"

namespace Hazel
{
	class SceneSerializer
	{
	private:
		SceneManager *manager;

	public:
		SceneSerializer(SceneManager &manager);

		void Serialize(Scene &scene, const std::string &filename);
		void Deserialize(Scene &scene, const std::string &filename);
	};
}
#pragma once

#include "GlfwException.h"

namespace Hazel
{
	class GlfwLoader
	{
	public:
		GlfwLoader();
		~GlfwLoader();

	private:
		void Init();
		void SetupErrorCallback();
		void InitGlfw();
		void SetupParameters();
		void Shutdown();
	};
}
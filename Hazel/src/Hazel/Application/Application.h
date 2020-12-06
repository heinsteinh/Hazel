#pragma once

#include "Private/BaseApplication.h"

namespace Hazel
{
	class Application : public BaseApplication
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void Quit();
	};

	std::unique_ptr<Application> CreateApplication(int argc, char *argv[]);
}
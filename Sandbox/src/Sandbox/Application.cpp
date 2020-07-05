#include "Hazel.h"
#include "Hazel/Core/EntryPoint.h"

#include "Log.h"
#include "Layer2D.h"

namespace Sandbox
{
	class Application : public Hazel::Application
	{
	public:
		Application()
		{
			Log::Info("Sandbox application creation");
			PushLayer(std::make_shared<Layer2D>(GetContext()));
			GetContext().Drawer.SetClearColor({0.45f, 0.55f, 0.60f, 1.00f});
		};
	};
}

std::unique_ptr<Hazel::Application> Hazel::CreateApplication()
{
	return std::make_unique<Sandbox::Application>();
}
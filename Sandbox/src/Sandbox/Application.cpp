#include "Hazel.h"
#include "Hazel/Core/EntryPoint.h"

#include "Log.h"
#include "SandboxLayer.h"
#include "TestParticle.h"

namespace Sandbox
{
	class Application : public Hazel::Application
	{
	public:
		Application()
		{
			Log::Info("Sandbox application creation");
			//PushLayer(std::make_shared<SandboxLayer>(GetContext()));
			PushLayer(std::make_shared<TestParticle>(GetContext()));
			GetContext().Drawer.SetClearColor({0.45f, 0.55f, 0.60f, 1.00f});
		};
	};
}

std::unique_ptr<Hazel::Application> CreateApplication()
{
	return std::make_unique<Sandbox::Application>();
}
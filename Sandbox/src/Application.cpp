#include "Hazel.h"
#include "Hazel/Application/Application.h"

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
			SetWindowTitle("Sandbox");
			PushLayer(std::make_shared<SandboxLayer>());
		};
	};
}

std::unique_ptr<Hazel::Application> Hazel::CreateApplication(int argc, char *argv[])
{
	return std::make_unique<Sandbox::Application>();
}
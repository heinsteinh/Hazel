#include "Hazel/Hazel.h"

#include "SandboxLayer.h"

namespace Sandbox
{
	class Sandbox : public Hazel::Application
	{
	public:
		Sandbox()
		{
			Hazel::Log::Info("Sandbox application creation");
			SetWindowTitle("Sandbox");
			PushLayer(std::make_shared<SandboxLayer>());
		};
	};
}

std::unique_ptr<Hazel::Application> Hazel::CreateApplication(int argc, char *argv[])
{
	return std::make_unique<Sandbox::Sandbox>();
}
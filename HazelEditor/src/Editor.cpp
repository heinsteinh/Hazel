#include "Hazel.h"
#include "Hazel/Logging/Log.h"
#include "Hazel/Application/Application.h"

#include "EditorLayer.h"

namespace Hazel
{
	class Editor : public Hazel::Application
	{
	public:
		Editor()
		{
			Log::Info("Sandbox application creation");
			SetWindowTitle("Sandbox");
			PushLayer(std::make_shared<EditorLayer>());
		};
	};
}

std::unique_ptr<Hazel::Application> CreateApplication(int argc, char *argv[])
{
	return std::make_unique<Hazel::Editor>();
}
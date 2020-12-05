#include "Hazel.h"
#include "Hazel/Logging/Log.h"
#include "Hazel/Application/Application.h"

#include "EditorLayer.h"

namespace Hazel
{
	class Editor : public Application
	{
	public:
		Editor()
		{
			Log::Info("Editor creation");
			SetWindowTitle("Hazel Editor");
			SetClearColor({0.30f, 0.30f, 0.30f, 1.00f});
			PushLayer(std::make_shared<EditorLayer>());
		};
	};

	std::unique_ptr<Application> CreateApplication(int argc, char *argv[])
	{
		return std::make_unique<Editor>();
	}
}
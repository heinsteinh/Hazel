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
			PushLayer(std::make_shared<EditorLayer>());
		};
	};

	std::unique_ptr<Application> CreateApplication(int argc, char *argv[])
	{
		return std::make_unique<Editor>();
	}
}
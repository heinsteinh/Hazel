#include "Hazel/Core/Application/Application.h"
#include "Hazel/Core/Logging/Log.h"

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
}
#include "Hazel/Core/Application/Application.h"
#include "Hazel/Core/Logging/Log.h"
#include "EditorLayer.h"

namespace Hazel
{
	class Editor : public Application
	{
	private:
		static ApplicationInfo CreateInfo()
		{
			ApplicationInfo info;
			info.Title = "Hazel Editor";
			info.ClearColor = {0.30f, 0.30f, 0.30f, 1.00f};
			return info;
		}

	public:
		Editor()
			: Application(CreateInfo())
		{
			Log::Info("Editor creation");
			PushLayer(std::make_unique<EditorLayer>());
		};
	};
}
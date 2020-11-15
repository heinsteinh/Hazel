#pragma once

namespace Hazel
{
	class OpenGLLoader
	{
	public:
		OpenGLLoader();

	private:
		void LoadGlad();
		void DisplayOpenGLInfo();
		void SetupConfiguration();
		void SetupDebugging();
	};
}
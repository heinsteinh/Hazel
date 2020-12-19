#pragma once

#include "Hazel/Core/Application/Application.h"
#include "Hazel/Core/Logging/Log.h"

extern std::unique_ptr<Hazel::Application> Hazel::CreateApplication(int argc, char **argv);

int main(int argc, char *argv[])
{
#ifdef HZ_DEBUG
	Hazel::CreateApplication(argc, argv)->Run();
#else
	try
	{
		Hazel::CreateApplication(argc, argv)->Run();
	}
	catch (Hazel::Exception &e)
	{
		Hazel::Log::Critical("Hazel exception: {}", e.GetDescription());
	}
	catch (std::exception &e)
	{
		Hazel::Log::Critical("Fatal exception: {}", e.what());
	}
	catch (...)
	{
		Hazel::Log::Critical("General failure");
	}
#endif
}
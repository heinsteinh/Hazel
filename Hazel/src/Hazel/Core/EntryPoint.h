#pragma once

#include "Hazel/Core/Application.h"
#include "Hazel/Logging/Log.h"

extern std::unique_ptr<Hazel::Application> CreateApplication();

int main(int argc, char *argv[])
{
	try
	{
		Hazel::CreateApplication()->Run();
	}
	catch (Hazel::Exception &e)
	{
		Hazel::Log::Critical("Hazel exception: {}", e.GetDescription());
	}
	catch (std::exception &e)
	{
		Hazel::Log::Critical("Unknown exception: {}", e.what());
	}
	catch (...)
	{
		Hazel::Log::Critical("General failure");
	}
}
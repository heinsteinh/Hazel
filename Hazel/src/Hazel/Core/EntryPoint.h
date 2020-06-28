#pragma once

#include "Hazel/Core/Application.h"
#include "Hazel/Core/UniquePtr.h"

extern Hazel::UniquePtr<Hazel::Application> CreateApplication();

int main(int argc, char *argv[])
{
	Hazel::CreateApplication()->Run();
}
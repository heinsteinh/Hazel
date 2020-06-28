#pragma once

#include "Hazel/Core/Application.h"

extern std::unique_ptr<Hazel::Application> CreateApplication();

int main(int argc, char *argv[])
{
	Hazel::CreateApplication()->Run();
}
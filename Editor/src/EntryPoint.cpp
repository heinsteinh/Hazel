#include "Editor/Application/Editor.h"

std::unique_ptr<Hazel::Application> Hazel::CreateApplication(int argc, char *argv[])
{
	return std::make_unique<Hazel::Editor>();
}
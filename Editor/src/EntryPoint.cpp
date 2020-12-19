#include "Hazel/Editor/Application/Editor.h"

namespace Hazel
{
	std::unique_ptr<Application> CreateApplication(int argc, char **argv)
	{
		return std::make_unique<Editor>();
	}
}
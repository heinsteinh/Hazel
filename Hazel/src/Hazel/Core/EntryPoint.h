#pragma once

#include "Hazel/Core/Application.h"
#include "Hazel/Core/UniquePtr.h"

extern Hazel::Application *Hazel::CreateApplication();

int main(int argc, char *argv[])
{
    Hazel::UniquePtr<Hazel::Application>(
        Hazel::CreateApplication()
        )->Run();
}
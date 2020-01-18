#pragma once

namespace Hazel
{
    class OpenGLLoader
    {
    public:
        OpenGLLoader();

    private:
        void Init();
        void LoadGlad();
        void DisplayOpenGLInfo();
        void SetupConfiguration();
        void SetupDebugging();
    };
}
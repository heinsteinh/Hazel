#pragma once

namespace Hazel
{
    class GlfwLoader
    {
    private:
        static void OnError(int error, const char *description);

    public:
        GlfwLoader();
        ~GlfwLoader();

    private:
        void Init();
        void SetupDebugging();
        void InitGlfw();
        void SetupConfiguration();
        void Shutdown();
    };
}
#pragma once

#include "Logger.h"

namespace Hazel
{
    class HAZEL_API Log
    {
    private:
        static Logger coreLogger;
        static Logger clientLogger;

    public:
        static constexpr Logger &GetCoreLogger()
        {
            return coreLogger;
        }

        static constexpr Logger &GetClientLogger()
        {
            return clientLogger;
        }

        Log() = delete;
    };

    template<typename ...Args>
    constexpr auto CoreTrace(Args &&...args)
    {
        Log::GetCoreLogger().Trace(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreDebug(Args &&...args)
    {
        Log::GetCoreLogger().Debug(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreInfo(Args &&...args)
    {
        Log::GetCoreLogger().Info(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreWarn(Args &&...args)
    {
        Log::GetCoreLogger().Warn(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreError(Args &&...args)
    {
        Log::GetCoreLogger().Error(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreCritical(Args &&...args)
    {
        Log::GetCoreLogger().Critical(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Trace(Args &&...args)
    {
        Log::GetClientLogger().Trace(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Debug(Args &&...args)
    {
        Log::GetClientLogger().Debug(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Info(Args &&...args)
    {
        Log::GetClientLogger().Info(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Warn(Args &&...args)
    {
        Log::GetClientLogger().Warn(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Error(Args &&...args)
    {
        Log::GetClientLogger().Error(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Critical(Args &&...args)
    {
        Log::GetClientLogger().Critical(std::forward<Args>(args)...);
    }
}
#pragma once

#include <memory>

#include "Core.h"
#include "Hazel/Utils/format.h"

namespace Hazel
{
    class LoggerImplementation;

    class HAZEL_API Logger
    {
    public:
        enum class Level
        {
            Trace,
            Debug,
            Info,
            Warn,
            Error,
            Critical
        };

    private:
        static Logger core;
        static Logger client;

        LoggerImplementation *implementation;

    public:
        static inline Logger &GetCoreLogger()
        {
            return core;
        }

        static inline Logger &GetClientLogger()
        {
            return client;
        }

        Logger(const std::string &tag);
        virtual ~Logger();

        Logger(const Logger &other) = delete;
        Logger &operator=(const Logger &other) = delete;

        Level GetLevel() const;
        void SetLevel(Level level);

        template<typename ...Args>
        inline void Log(Level level, const Args &...args)
        {
            LogString(level, fmt::format(args...));
        }

        template<typename ...Args>
        constexpr auto Trace(Args &&...args)
        {
            return Log(Level::Trace, std::forward(args...));
        }

        template<typename ...Args>
        constexpr auto Debug(Args &&...args)
        {
            return Log(Level::Debug, std::forward(args...));
        }

        template<typename ...Args>
        constexpr auto Info(Args &&...args)
        {
            return Log(Level::Info, std::forward(args...));
        }

        template<typename ...Args>
        constexpr auto Warn(Args &&...args)
        {
            return Log(Level::Warn, std::forward(args...));
        }

        template<typename ...Args>
        constexpr auto Error(Args &&...args)
        {
            return Log(Level::Error, std::forward(args...));
        }

        template<typename ...Args>
        constexpr auto Critical(Args &&...args)
        {
            return Log(Level::Critical, std::forward(args...));
        }

    private:
        void LogString(Level level, const std::string &message) const;
    };

    template<typename ...Args>
    constexpr auto CoreTrace(Args &&...args)
    {
        return Logger::GetCoreLogger().Trace(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto CoreDebug(Args &&...args)
    {
        return Logger::GetCoreLogger().Debug(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto CoreInfo(Args &&...args)
    {
        return Logger::GetCoreLogger().Info(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto CoreWarn(Args &&...args)
    {
        return Logger::GetCoreLogger().Warn(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto CoreError(Args &&...args)
    {
        return Logger::GetCoreLogger().Error(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto CoreCritical(Args &&...args)
    {
        return Logger::GetCoreLogger().Critical(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Trace(Args &&...args)
    {
        return Logger::GetClientLogger().Trace(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Debug(Args &&...args)
    {
        return Logger::GetClientLogger().Debug(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Info(Args &&...args)
    {
        return Logger::GetClientLogger().Info(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Warn(Args &&...args)
    {
        return Logger::GetClientLogger().Warn(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Error(Args &&...args)
    {
        return Logger::GetClientLogger().Error(std::forward(args...));
    }

    template<typename ...Args>
    constexpr auto Critical(Args &&...args)
    {
        return Logger::GetClientLogger().Critical(std::forward(args...));
    }
}
#pragma once

#include <string>
#include <utility>

#include "Core.h"

#include "spdlog/spdlog.h"

template class HAZEL_API std::shared_ptr<spdlog::logger>;

namespace Hazel
{
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

        std::shared_ptr<spdlog::logger> logger;
        Level level;

    public:
        static constexpr Logger &GetCoreLogger()
        {
            return core;
        }

        static constexpr Logger &GetClientLogger()
        {
            return client;
        }

        Logger(const std::string &tag);
        virtual ~Logger() = default;

        Logger(const Logger &other) = delete;
        Logger &operator=(const Logger &other) = delete;

        Level GetLevel() const;
        void SetLevel(Level level);

        template<typename ...Args>
        inline void Log(Level level, const Args &...args)
        {
            logger->log(static_cast<spdlog::level::level_enum>(level), args...);
        }

        template<typename ...Args>
        constexpr auto Trace(Args &&...args)
        {
            return Log(Level::Trace, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Debug(Args &&...args)
        {
            return Log(Level::Debug, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Info(Args &&...args)
        {
            return Log(Level::Info, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Warn(Args &&...args)
        {
            return Log(Level::Warn, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Error(Args &&...args)
        {
            return Log(Level::Error, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Critical(Args &&...args)
        {
            return Log(Level::Critical, std::forward<Args>(args)...);
        }
    };

    template<typename ...Args>
    constexpr auto CoreTrace(Args &&...args)
    {
        return Logger::GetCoreLogger().Trace(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreDebug(Args &&...args)
    {
        return Logger::GetCoreLogger().Debug(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreInfo(Args &&...args)
    {
        return Logger::GetCoreLogger().Info(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreWarn(Args &&...args)
    {
        return Logger::GetCoreLogger().Warn(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreError(Args &&...args)
    {
        return Logger::GetCoreLogger().Error(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto CoreCritical(Args &&...args)
    {
        return Logger::GetCoreLogger().Critical(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Trace(Args &&...args)
    {
        return Logger::GetClientLogger().Trace(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Debug(Args &&...args)
    {
        return Logger::GetClientLogger().Debug(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Info(Args &&...args)
    {
        return Logger::GetClientLogger().Info(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Warn(Args &&...args)
    {
        return Logger::GetClientLogger().Warn(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Error(Args &&...args)
    {
        return Logger::GetClientLogger().Error(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    constexpr auto Critical(Args &&...args)
    {
        return Logger::GetClientLogger().Critical(std::forward<Args>(args)...);
    }
}
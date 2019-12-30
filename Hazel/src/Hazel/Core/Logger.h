#pragma once

#include "spdlog/spdlog.h"

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
        std::shared_ptr<spdlog::logger> logger;
        Level level;

    public:
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
            Log(Level::Trace, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Debug(Args &&...args)
        {
            Log(Level::Debug, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Info(Args &&...args)
        {
            Log(Level::Info, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Warn(Args &&...args)
        {
            Log(Level::Warn, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Error(Args &&...args)
        {
            Log(Level::Error, std::forward<Args>(args)...);
        }

        template<typename ...Args>
        constexpr auto Critical(Args &&...args)
        {
            Log(Level::Critical, std::forward<Args>(args)...);
        }
    };
}
#include "Logger.h"

#include <unordered_map>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel
{
    class LoggerImplementation
    {
    private:
        static const std::unordered_map<Logger::Level, spdlog::level::level_enum> mapping;

        std::shared_ptr<spdlog::logger> logger;
        Logger::Level level;

    public:
        LoggerImplementation(const std::string &tag)
            : logger(spdlog::stdout_color_mt(tag))
        {
            SetLevel(level);
        }

        inline Logger::Level GetLevel() const
        {
            return level;
        }

        inline void SetLevel(Logger::Level level)
        {
            this->level = level;
            logger->set_level(mapping.at(level));
        }

        inline void LogString(Logger::Level level, const std::string &message)
        {
            logger->log(mapping.at(level), message);
        }
    };

    const std::unordered_map<Logger::Level, spdlog::level::level_enum> LoggerImplementation::mapping = {
        {Logger::Level::Trace, spdlog::level::trace},
        {Logger::Level::Debug, spdlog::level::debug},
        {Logger::Level::Info, spdlog::level::info},
        {Logger::Level::Warn, spdlog::level::warn},
        {Logger::Level::Error, spdlog::level::err},
        {Logger::Level::Critical, spdlog::level::critical}
    };

    Logger Logger::core("HAZEL");
    Logger Logger::client("APP");

    Logger::Logger(const std::string &tag)
        : implementation(new LoggerImplementation(tag))
    {
    }

    Logger::~Logger()
    {
        delete implementation;
    }

    Logger::Level Logger::GetLevel() const
    {
        return implementation->GetLevel();
    }

    void Logger::SetLevel(Level level)
    {
        implementation->SetLevel(level);
    }

    void Logger::LogString(Level level, const std::string &message) const
    {
        implementation->LogString(level, message);
    }
}
#include "Logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel
{
    Logger::Logger(const std::string &tag)
        : logger(spdlog::stdout_color_mt(tag))
    {
        SetLevel(Level::Debug);
        logger->set_pattern("%^[%l][%T] %n: %v%$");
    }

    Logger::Level Logger::GetLevel() const
    {
        return level;
    }

    void Logger::SetLevel(Level level)
    {
        this->level = level;
        logger->set_level(static_cast<spdlog::level::level_enum>(level));
    }
}
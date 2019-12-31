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
}
#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "LogLevel.h"

namespace Hazel
{
	class Logger
	{
	private:
		std::shared_ptr<spdlog::logger> logger;
		LogLevel level;

	public:
		inline Logger(const std::string &tag)
			: logger(spdlog::stdout_color_mt(tag))
		{
			SetLevel(LogLevel::Debug);
			logger->set_pattern("%^[%l][%T] %n: %v%$");
		}

		Logger(const Logger &other) = delete;
		Logger &operator=(const Logger &other) = delete;

		constexpr LogLevel GetLevel() const
		{
			return level;
		}

		inline void SetLevel(LogLevel level)
		{
			this->level = level;
			logger->set_level(static_cast<spdlog::level::level_enum>(level));
		}

		template<typename ...Args>
		inline void Log(LogLevel level, Args &&...args)
		{
			logger->log(static_cast<spdlog::level::level_enum>(level), std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Trace(Args &&...args)
		{
			Log(LogLevel::Trace, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Debug(Args &&...args)
		{
			Log(LogLevel::Debug, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Info(Args &&...args)
		{
			Log(LogLevel::Info, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Warn(Args &&...args)
		{
			Log(LogLevel::Warn, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Error(Args &&...args)
		{
			Log(LogLevel::Error, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		constexpr auto Critical(Args &&...args)
		{
			Log(LogLevel::Critical, std::forward<Args>(args)...);
		}
	};
}
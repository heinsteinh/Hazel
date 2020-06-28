#pragma once

#include "Logger.h"

namespace Hazel
{
	class Log
	{
	private:
		static inline Logger logger{"Hazel"};

	public:
		static inline LogLevel GetLevel()
		{
			return logger.GetLevel();
		}

		static inline void SetLevel(LogLevel level)
		{
			logger.SetLevel(level);
		}

		template<typename ...Args>
		static constexpr auto Trace(Args &&...args)
		{
			logger.Trace(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static constexpr auto Debug(Args &&...args)
		{
			logger.Debug(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static constexpr auto Info(Args &&...args)
		{
			logger.Info(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static constexpr auto Warn(Args &&...args)
		{
			logger.Warn(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static constexpr auto Error(Args &&...args)
		{
			logger.Error(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static constexpr auto Critical(Args &&...args)
		{
			logger.Critical(std::forward<Args>(args)...);
		}

		Log() = delete;
	};
}
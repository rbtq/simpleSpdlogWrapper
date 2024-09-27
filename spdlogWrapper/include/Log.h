#pragma once
#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
//#include <cmath>

namespace rbtq
{
	class Log
	{
	private: 
		static short m_minConsoleLogLevel; //!<minimum log level for console output
		static short m_minFileLogLevel; //!<minimum log level for file output
		static bool m_consoleEnabled; //!<is the console logger enabled?
		static bool m_fileEnabled; //!<is the file logger enabled?

		static std::shared_ptr<spdlog::logger> s_consoleLogger; //!< Console logger
		static std::shared_ptr<spdlog::logger> s_fileLogger; //!< File logger

		static bool shouldConsoleLog(short logLevel); //!<console log check
		static bool shouldFileLog(short logLevel); //!<file log check



		void startFileLogger(); //!<try to start the file logger
		void startConsoleLogger(); //!<start the console logger
		void setupLogLevel(); //!<setup the log level

	public:
		void start(bool consoleEnabled, bool fileEnabled, short consoleLogLevel = 1, short fileLogLevel = 2); //!< Start the logger
		void stop(); //!< Stop the logger

		template<class ...Args>
		static void trace(Args&&... args);

		template<class ...Args>
		static void debug(Args&&... args);

		template<class ...Args>
		static void info(Args&&... args);

		template<class ...Args>
		static void warn(Args&&... args);

		template<class ...Args>
		static void error(Args&&... args);

		template<class ...Args>
		static void critical(Args&&... args);
	};



	template<class ...Args>
	static void Log::trace(Args&&... args) //trace
	{
		if (Log::shouldConsoleLog(0))
		{
			s_consoleLogger->trace(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(0)) {
			s_fileLogger->trace(std::forward<Args>(args) ...);
		}

	}

	template<class ...Args>
	static void Log::debug(Args&&... args) //debug
	{
		if (Log::shouldConsoleLog(1))
		{
			s_consoleLogger->debug(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(1)) {
			s_fileLogger->debug(std::forward<Args>(args) ...);
		}
	}

	template<class ...Args>
	static void Log::info(Args&&... args) //info
	{
		if (Log::shouldConsoleLog(2))
		{
			s_consoleLogger->info(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(2)) {
			s_fileLogger->info(std::forward<Args>(args) ...);
		}
	}

	template<class ...Args>
	static void Log::warn(Args&&... args)
	{
		if (Log::shouldConsoleLog(3))
		{
			s_consoleLogger->warn(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(3)) {
			s_fileLogger->warn(std::forward<Args>(args) ...);
		}
	}

	template<class ...Args>
	static void Log::error(Args&&... args)
	{
		if (Log::shouldConsoleLog(4))
		{
			s_consoleLogger->error(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(4)) {
			s_fileLogger->error(std::forward<Args>(args) ...);
		}
	}

	template<class ...Args>
	static void Log::critical(Args&&... args)
	{
		if (Log::shouldConsoleLog(5))
		{
			s_consoleLogger->critical(std::forward<Args>(args) ...);
		}
		if (Log::shouldFileLog(5)) {
			s_fileLogger->critical(std::forward<Args>(args) ...);
		}
	}
}
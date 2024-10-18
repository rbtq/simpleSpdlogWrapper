#pragma once
#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "logSettings.h"

namespace rbtq
{
	class Log
	{
	private: 
		static LogSettings s_settings; //!<settings for logger

		static std::shared_ptr<spdlog::logger> s_consoleLogger; //!< Console logger
		static std::shared_ptr<spdlog::logger> s_fileLogger; //!< File logger

		static bool shouldConsoleLog(short logLevel); //!<console log check
		static bool shouldFileLog(short logLevel); //!<file log check



		void startFileLogger(); //!<try to start the file logger
		void startConsoleLogger(); //!<start the console logger
		void setupLogLevel(); //!<setup the log level

	public:
		void start(LogSettings settings); //!< Start the logger
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



	std::shared_ptr<spdlog::logger> Log::s_consoleLogger = nullptr;
	std::shared_ptr<spdlog::logger> Log::s_fileLogger = nullptr;
	LogSettings Log::s_settings;

	bool Log::shouldConsoleLog(short logLevel) { return logLevel >= s_settings.m_minConsoleLogLevel && s_settings.m_shouldConsoleLog; }; //!<console log check
	bool Log::shouldFileLog(short logLevel) { return logLevel >= s_settings.m_minFileLogLevel && s_settings.m_shouldFileLog; }; //!<file log check


	void Log::startFileLogger() { //!<try start the file logger
		char filepath[256] = ""; //path of the log files
		char time[128]; //!<time when it was created
		try
		{
			//try create a file to log to
			std::time_t t = std::time(nullptr);
			std::strftime(time, sizeof(time), "%d_%m_%y %I_%M_%S", std::localtime(&t));

			strcat_s(filepath, s_settings.m_directory);
			strcat_s(filepath, time);
			strcat_s(filepath, ".txt");

			s_fileLogger = spdlog::basic_logger_mt("File", filepath);
		}
		catch (const spdlog::spdlog_ex& e)
		{
			//disable logger and report error to user
			s_fileLogger.reset();
			s_settings.m_shouldFileLog = false;
			Log::error("Could not start file logger: {0}", e.what());
			return;
		}
	}

	void Log::startConsoleLogger() {
		spdlog::set_pattern("[%H:%M:%S] [%^---%L---%$] [thread %t] %v");
		s_consoleLogger = spdlog::stdout_color_mt("Console");
	}

	void Log::setupLogLevel() {

		short logLevel;

		if (s_settings.m_shouldConsoleLog && s_settings.m_shouldFileLog) {
			logLevel = std::fmin(s_settings.m_minFileLogLevel, s_settings.m_minConsoleLogLevel);
		}
		else if (s_settings.m_shouldFileLog) {
			logLevel = s_settings.m_minFileLogLevel;
		}
		else if (s_settings.m_shouldConsoleLog) {
			logLevel = s_settings.m_minConsoleLogLevel;
		}
		else logLevel = 0;

		//validation
		if (logLevel >= spdlog::level::level_enum::n_levels || logLevel < 0) {
			std::cout << "[spdlogWrapper Error] Invalid log level set: "
				<< logLevel << " > Max: " << (spdlog::level::level_enum::n_levels - 1) << std::endl;
			return;
		}
		//now set it
		spdlog::set_level((spdlog::level::level_enum)logLevel);
	}


	void Log::start(LogSettings settings)
	{
		//set values
		s_settings = settings;
		//setup log level and start loggers if enabled
		setupLogLevel();
		if (s_settings.m_shouldConsoleLog) startConsoleLogger();
		if (s_settings.m_shouldFileLog) startFileLogger();

		if (s_settings.m_shouldConsoleLog) {
			Log::info("Successfully started console logger");
		}
		if (s_settings.m_shouldFileLog) {
			Log::info("Successfully started file logger");
		}

	}

	void Log::stop()
	{
		//log final message
		if (s_settings.m_shouldConsoleLog) {
			Log::info("Stopping console logger");
		}
		if (s_settings.m_shouldFileLog) {
			Log::info("Stopping file logger");
		}

		//delete
		if (s_settings.m_shouldConsoleLog) s_consoleLogger.reset();
		if (s_settings.m_shouldFileLog) s_fileLogger.reset();
	}
}
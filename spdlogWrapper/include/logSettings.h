/**\file LogSettings.h*/
#pragma once
/**\class LogSettings - class that contains all the settings for the wrapper*/
namespace ssw {
	class LogSettings {
	public:
		bool m_shouldConsoleLog = true; //!<should log statements output to console
		char m_minConsoleLogLevel = 0; //!<the minimum log level requirement for a maessage to be output to the console
		bool m_shouldFileLog = true; //!<should log statements output to a file
		char m_minFileLogLevel = 0; //!<the minimum log level requirement for a maessage to be output to a file
		char m_directory[256] = "logs/"; //!<the directory that the log files will be outputted to
		std::string m_pattern = "[%H:%M:%S] [%^---%L---%$] %v"; //!<the pattern for log messages
	};
}
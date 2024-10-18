/**\file LogSettings.h*/
#pragma once
/**\class LogSettings - class that contains all the settings for the wrapper*/
namespace rbtq {
	class LogSettings {
	public:
		bool m_shouldConsoleLog = true; //!<should log statements output to console
		char m_minConsoleLogLevel = 1; //!<the minimum log level requirement for a maessage to be output to the console
		bool m_shouldFileLog = false; //!<should log statements output to a file
		char m_minFileLogLevel = 1; //!<the minimum log level requirement for a maessage to be output to a file
	};
}
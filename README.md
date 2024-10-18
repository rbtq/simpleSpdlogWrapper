# simpleSpdlogWrapper
A simple wrapper for SpdLog that is free to use.
https://github.com/gabime/spdlog - check the licence here before using, is free to use in any way as of writing.

Premake5:
Make sure to include the spdlog directory as well or it wont work
![image](https://github.com/user-attachments/assets/d2d553d3-1a6e-4daf-bce7-3db947962d0d)



Quick start:

//include the header file
#include "Log.h"

int main() {
	
 	//init logger - put this in a place that can be accessed across the entire program and will last for the duration of the program
	rbtq::Log programLogger;

	//run start function before logging, default constructor gives default settings
	programLogger.start(rbtq::LogSettings());

	//do stuff
	programLogger.trace("Test1");
	programLogger.trace("Test {0} A", 0); //{0} is how you add non-string parameters into the message
	programLogger.debug("Test {0}", 1);
	programLogger.info("Test {0}", 2);
	programLogger.warn("Test {0}", 3);
	programLogger.error("Test {0} {1}", 4, 10); //can use {1,2,3} etc if you need to add more values into the message
	programLogger.critical("Test {1} {0}", 5, 10); //does not need to be in order

	//run stop function after logging, cleanup
	programLogger.stop();

	return 0;
}

Configuration Settings
class LogSettings {
	
 public:
		
  bool m_shouldConsoleLog = true; //!<should log statements output to console
		
  char m_minConsoleLogLevel = 1; //!<the minimum log level requirement for a maessage to be output to the console
		
  bool m_shouldFileLog = false; //!<should log statements output to a file
		
  char m_minFileLogLevel = 1; //!<the minimum log level requirement for a maessage to be output to a file
  
};

Log Levels
    trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5
    
Setting the minimum log level higher than a log level will disable it.
e.g a minimum log level of 1 will mean trace messages will not be outputted
If you would like more features, raise an issue.
    

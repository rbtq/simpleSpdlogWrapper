
#include "Log.h"

int main() {
	//init logger
	rbtq::Log programLogger;


	//run start function before logging
	//start(consoleEnabled, fileEnabled, minimum console log level, minimum file log level)
	/*
	Log levels
	trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5,
	*/
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
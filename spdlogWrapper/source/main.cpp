
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
	programLogger.start(true, true, 0, 0);

	//do stuff
	programLogger.trace("Test1");
	programLogger.trace("Test {0}", 0);
	programLogger.debug("Test {0}", 1);
	programLogger.info("Test {0}", 2);
	programLogger.warn("Test {0}", 3);
	programLogger.error("Test {0}", 4);
	programLogger.critical("Test {0} {1}", 5, 10);

	//run stop function after logging
	programLogger.stop();

	return 0;
}
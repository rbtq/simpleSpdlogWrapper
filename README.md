# simpleSpdlogWrapper
A simple wrapper for SpdLog that is free to use.
https://github.com/gabime/spdlog - check the licence here before using, is free to use in any way as of writing.

If you would like more features, raise an issue.

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

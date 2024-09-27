
#include "Log.h"

int main() {
	//init logger
	rbtq::Log programLogger;
	//run start function
	programLogger.start(true, true, 0, 0);
	//do stuff
	programLogger.trace("Test {0}", 0);
	programLogger.debug("Test {0}", 1);
	programLogger.info("Test {0}", 2);
	programLogger.warn("Test {0}", 3);
	programLogger.error("Test {0}", 4);
	programLogger.critical("Test {0}", 5);
	//stop
	programLogger.stop();

	return 0;
}
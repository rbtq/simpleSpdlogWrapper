# simpleSpdlogWrapper
A simple wrapper for SpdLog that is free to use.
https://github.com/gabime/spdlog - check the licence here before using, is free to use in any way as of writing.

If you would like more features, raise an issue.

How to use - Sample program

	//init logger
	rbtq::Log programLogger; - make sure to put this in a place that can be accessed across the program, like a config file.

	//run start function before logging
	//start(consoleEnabled, fileEnabled, minimum console log level, minimum file log level)
	/*
	Log levels
	trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    error = 4,
    critical = 5,
	*/
	programLogger.start(true, true, 0, 0);

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

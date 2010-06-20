#include "ConsoleLogger.h"
#include "GoGoFactory.h"
#include "Configuration.h"

#include <database/GunzDB.h>

#include <cockpit/MatchServer.h>

#include <exception>
#include <fstream>
#include <boost/asio/io_service.hpp>
#include <boost/thread.hpp>

using namespace boost;

Configuration get_config(const char* filename)
{
	std::ifstream is(filename);
	return Configuration(is);
}

int main()
{
	ConsoleLogger loggerImpl;
	cockpit::Logger* logger = &loggerImpl;

	GoGoFactory factory(logger);
	Configuration conf = get_config("gogo.conf");

	try {
		cockpit::MatchServer server(logger, &factory, conf.get_value<uint16_t>("server.port", 6000));

		server.start();
		server.wait();

	} catch(const std::exception& ex) {
		logger->error(format("Fatal error: %1%") % ex.what());
		return 1;
	} catch(...) {
		logger->error("Unknown exception encountered. This is a programming error. Report this message to the bugtracker.");
		return 2;
	}

	return 0;
}

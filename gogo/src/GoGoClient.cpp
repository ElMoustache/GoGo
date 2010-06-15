#include "GoGoClient.h"

#include <cockpit/Transmitter.h>
#include <cockpit/packet/Registry.h>

#include "MUIDSanta.h"

#include <cassert>

using namespace std;
using namespace boost;
using namespace cockpit;

GoGoClient::GoGoClient(Logger* _logger, MUIDSanta* _santa)
{
	assert(_logger);
	logger = _logger;

	assert(_santa);
	santa = _santa;
	myMUID = santa->get();
}

void GoGoClient::initialize(Transmitter* _transmitter, packet::Registry* _registry)
{
	assert(_transmitter);
	assert(_registry);

	transmitter = _transmitter;
	registry = _registry;

	register_handler(registry->Match_Login, bind(&GoGoClient::OnMatchLogin, this, _1, _2, _3, _4));
}

GoGoClient::~GoGoClient()
{
	santa->give_back(myMUID);

	// Disconnect all active signals.
	for(vector<signals2::connection>::iterator i = activeHandlers.begin(); i != activeHandlers.end(); ++i)
		i->disconnect();
}

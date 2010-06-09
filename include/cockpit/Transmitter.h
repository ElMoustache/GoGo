#pragma once

namespace cockpit {

namespace packet { class Packet; }

/**
	The Transmitter class acts as an interface to the ClientHandler's so they
	may react accordingly to recieved packets, sending appropriate responses.
	If responses need to be processed, just hook the handler.
*/
class Transmitter
{
public:
	/**
		Sends a raw packet across the 'net to our client. It is assumed you are
		already connected to the client.

		@param packet A pointer to a valid packet to send.
	*/
	virtual void send(const packet::Packet* packet) = 0;

	virtual ~Transmitter()
	{
	}
};

}

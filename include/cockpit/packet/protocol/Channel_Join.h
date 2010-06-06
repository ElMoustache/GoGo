/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <boost/cstdint.hpp>
#include <cockpit/packet/Packet.h>
#include <cockpit/packet/Parameters.h>

namespace cockpit {
namespace packet {
namespace protocol {

// Join a Channel
class Channel_Join : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidChannel;

public:
	enum { packetID = 1205 };

	Channel_Join(packet::MUID uidPlayer, packet::MUID uidChannel);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Channel_Join()
	{
	}

};

}
}
}
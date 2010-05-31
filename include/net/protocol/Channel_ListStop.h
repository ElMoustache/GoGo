/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <net/packet.h>
#include <boost/cstdint.hpp>
#include <net/PacketParameters.h>

namespace packet {
namespace protocol {

// Channel List transmit stop
class Channel_ListStop : public Packet
{
private:
	packet::MUID uidPlayer;

public:
	enum { packetID = 1212 };

	Channel_ListStop(packet::MUID uidPlayer);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Channel_ListStop()
	{
	}

};

}
}
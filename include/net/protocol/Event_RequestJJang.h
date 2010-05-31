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

// Request JJang mark to a Player
class Event_RequestJJang : public Packet
{
private:
	packet::string strTargetName;

public:
	enum { packetID = 611 };

	Event_RequestJJang(packet::string strTargetName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Event_RequestJJang()
	{
	}

};

}
}
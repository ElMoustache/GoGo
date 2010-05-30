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

// Response stage quest level
class Quest_ResponseLevel : public Packet
{
private:
	packet::int32 Questlevel;

public:
	enum { packetID = 6102 };

	Quest_ResponseLevel(packet::int32 Questlevel);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
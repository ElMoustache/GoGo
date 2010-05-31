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

// Request Challenge a Ladder
class Match_Ladder_Request_Challenge : public Packet
{
private:
	packet::int32 MemberCount;
	packet::uint32 Options;
	packet::blob MemberNames;

public:
	enum { packetID = 1571 };

	Match_Ladder_Request_Challenge(packet::int32 MemberCount, packet::uint32 Options, packet::blob MemberNames);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Match_Ladder_Request_Challenge()
	{
	}

};

}
}
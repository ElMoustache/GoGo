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

// Response Agreed Create Clan
class Match_Clan_AgreedResponseCreateClan : public Packet
{
private:
	packet::int32 Result;

public:
	enum { packetID = 2005 };

	Match_Clan_AgreedResponseCreateClan(packet::int32 Result);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Match_Clan_AgreedResponseCreateClan()
	{
	}

};

}
}
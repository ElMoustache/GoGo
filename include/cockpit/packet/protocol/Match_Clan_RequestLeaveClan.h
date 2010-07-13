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

// Request Leave Clan
class Match_Clan_RequestLeaveClan : public Packet
{
private:
	packet::MUID uidChar;

public:
	enum { packetID = 2014 };

	Match_Clan_RequestLeaveClan(const packet::MUID& uidChar);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Clan_RequestLeaveClan()
	{
	}

};

}
}
}

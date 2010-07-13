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

// Request Close Clan
class Match_Clan_RequestCloseClan : public Packet
{
private:
	packet::MUID uidChar;
	packet::string ClanName;

public:
	enum { packetID = 2006 };

	Match_Clan_RequestCloseClan(const packet::MUID& uidChar, const packet::string& ClanName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Clan_RequestCloseClan()
	{
	}

};

}
}
}

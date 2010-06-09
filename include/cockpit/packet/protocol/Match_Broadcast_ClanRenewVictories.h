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

// Broadcast Clan Renew Victories
class Match_Broadcast_ClanRenewVictories : public Packet
{
private:
	packet::string strWinnerClanName;
	packet::string strLoserClanName;
	packet::int32 nVictories;

public:
	enum { packetID = 2200 };

	Match_Broadcast_ClanRenewVictories(packet::string strWinnerClanName, packet::string strLoserClanName, packet::int32 nVictories);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Broadcast_ClanRenewVictories()
	{
	}

};

}
}
}

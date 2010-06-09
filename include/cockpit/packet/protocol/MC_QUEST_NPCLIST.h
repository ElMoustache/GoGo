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

// Send npc info list to client.
class MC_QUEST_NPCLIST : public Packet
{
private:
	packet::blob NPCinfolist;
	packet::int32 eGameType;

public:
	enum { packetID = 6014 };

	MC_QUEST_NPCLIST(packet::blob NPCinfolist, packet::int32 eGameType);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~MC_QUEST_NPCLIST()
	{
	}

};

}
}
}

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

// Npc Spawn
class Quest_NPCSpawn : public Packet
{
private:
	packet::MUID uidChar;
	packet::MUID nNpcUID;
	packet::uint8 nNpcType;
	packet::uint8 PositionIndex;

public:
	enum { packetID = 6000 };

	Quest_NPCSpawn(const packet::MUID& uidChar, const packet::MUID& nNpcUID, const packet::uint8& nNpcType, const packet::uint8& PositionIndex);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_NPCSpawn()
	{
	}

};

}
}
}

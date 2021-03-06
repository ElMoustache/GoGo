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

// NPC Spawn
class Quest_Test_RequestNPCSpawn : public Packet
{
private:
	packet::int32 NPCType;
	packet::int32 NPCCount;

public:
	enum { packetID = 6901 };

	Quest_Test_RequestNPCSpawn(const packet::int32& NPCType, const packet::int32& NPCCount);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_Test_RequestNPCSpawn()
	{
	}

};

}
}
}

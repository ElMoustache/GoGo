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

// Quest Sector Bonus
class Quest_SectorBonus : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::uint32 XPBonus;
	packet::uint32 BPBonus;

public:
	enum { packetID = 6062 };

	Quest_SectorBonus(packet::MUID uidPlayer, packet::uint32 XPBonus, packet::uint32 BPBonus);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Quest_SectorBonus()
	{
	}

};

}
}
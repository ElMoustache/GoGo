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

// Spawn WorldItem
class Match_WorldItem_Spawn : public Packet
{
private:
	packet::blob SpawnInfo;

public:
	enum { packetID = 1543 };

	Match_WorldItem_Spawn(packet::blob SpawnInfo);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_WorldItem_Spawn()
	{
	}

};

}
}
}
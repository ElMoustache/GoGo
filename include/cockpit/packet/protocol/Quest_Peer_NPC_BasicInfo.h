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

// NPC BasicInfo
class Quest_Peer_NPC_BasicInfo : public Packet
{
private:
	packet::blob Info;

public:
	enum { packetID = 6040 };

	Quest_Peer_NPC_BasicInfo(const packet::blob& Info);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_Peer_NPC_BasicInfo()
	{
	}

};

}
}
}

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

// Stage Go
class Stage_StageGo : public Packet
{
private:
	packet::uint32 RoomNo;

public:
	enum { packetID = 1331 };

	Stage_StageGo(packet::uint32 RoomNo);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
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

// Pong
class HShield_Pong : public Packet
{
private:
	packet::uint32 TimeStamp;
	packet::blob AckMsg;

public:
	enum { packetID = 325 };

	HShield_Pong(packet::uint32 TimeStamp, packet::blob AckMsg);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~HShield_Pong()
	{
	}

};

}
}
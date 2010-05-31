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

// Request UID
class Net_RequestUID : public Packet
{
private:
	packet::int32 Size;

public:
	enum { packetID = 343 };

	Net_RequestUID(packet::int32 Size);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Net_RequestUID()
	{
	}

};

}
}
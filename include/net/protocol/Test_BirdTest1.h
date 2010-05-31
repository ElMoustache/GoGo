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

// BirdTest1
class Test_BirdTest1 : public Packet
{
private:
	packet::int32 Result;
	packet::MUID uidPlayer;
	packet::blob Dummy;

public:
	enum { packetID = 60001 };

	Test_BirdTest1(packet::int32 Result, packet::MUID uidPlayer, packet::blob Dummy);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Test_BirdTest1()
	{
	}

};

}
}
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

// ACK for BridgePeer
class Match_BridgePeerACK : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::int32 nCode;

public:
	enum { packetID = 1007 };

	Match_BridgePeerACK(packet::MUID uidPlayer, packet::int32 nCode);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
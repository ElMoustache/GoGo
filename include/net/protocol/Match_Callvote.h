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

// Callvote
class Match_Callvote : public Packet
{
private:
	packet::string strDiscuss;
	packet::string strArg;

public:
	enum { packetID = 2100 };

	Match_Callvote(packet::string strDiscuss, packet::string strArg);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
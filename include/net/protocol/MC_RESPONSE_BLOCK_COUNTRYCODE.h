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

// response block ip connected.
class MC_RESPONSE_BLOCK_COUNTRYCODE : public Packet
{
private:
	packet::string Comment;

public:
	enum { packetID = 50001 };

	MC_RESPONSE_BLOCK_COUNTRYCODE(packet::string Comment);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
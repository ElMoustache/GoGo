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

// request new client hash value
class MC_REQUEST_XTRAP_HASHVALUE : public Packet
{
private:
	packet::string newrandomvalue;

public:
	enum { packetID = 8001 };

	MC_REQUEST_XTRAP_HASHVALUE(packet::string newrandomvalue);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
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

// send gamble item info list to client
class MC_RESPONSE_GAMBLEITEMLIST : public Packet
{
private:
	packet::blob Gambleitemlist;

public:
	enum { packetID = 1827 };

	MC_RESPONSE_GAMBLEITEMLIST(packet::blob Gambleitemlist);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
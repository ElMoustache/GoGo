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

// Response Character Info Detail
class Match_ResponseCharInfoDetail : public Packet
{
private:
	packet::blob CharInfo;

public:
	enum { packetID = 1718 };

	Match_ResponseCharInfoDetail(packet::blob CharInfo);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
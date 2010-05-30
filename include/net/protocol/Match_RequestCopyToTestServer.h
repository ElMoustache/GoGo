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

// Request Copy To TestServer
class Match_RequestCopyToTestServer : public Packet
{
private:
	packet::MUID uidChar;

public:
	enum { packetID = 1715 };

	Match_RequestCopyToTestServer(packet::MUID uidChar);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
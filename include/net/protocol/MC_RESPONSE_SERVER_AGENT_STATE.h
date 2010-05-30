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

// response current state of server and agent
class MC_RESPONSE_SERVER_AGENT_STATE : public Packet
{
private:
	packet::int32 serverstate;
	packet::int32 agentstate;

public:
	enum { packetID = 31028 };

	MC_RESPONSE_SERVER_AGENT_STATE(packet::int32 serverstate, packet::int32 agentstate);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
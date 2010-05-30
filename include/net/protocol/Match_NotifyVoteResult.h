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

// Notify Vote Result
class Match_NotifyVoteResult : public Packet
{
private:
	packet::string strDiscuss;
	packet::int32 nResult;

public:
	enum { packetID = 2102 };

	Match_NotifyVoteResult(packet::string strDiscuss, packet::int32 nResult);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
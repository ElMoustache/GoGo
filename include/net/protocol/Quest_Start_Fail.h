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

// Failed start quest.
class Quest_Start_Fail : public Packet
{
private:
	packet::int32 Failedtype_;
	packet::MUID pairparam;

public:
	enum { packetID = 6060 };

	Quest_Start_Fail(packet::int32 Failedtype_, packet::MUID pairparam);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
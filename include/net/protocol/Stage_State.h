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

// Change State In Stage
class Stage_State : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidStage;
	packet::int32 nState;
	packet::int32 zero;

public:
	enum { packetID = 1422 };

	Stage_State(packet::MUID uidPlayer, packet::MUID uidStage, packet::int32 nState, packet::int32 zero);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Stage_State()
	{
	}

};

}
}
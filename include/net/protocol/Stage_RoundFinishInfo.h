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

// Update Round Finished Info
class Stage_RoundFinishInfo : public Packet
{
private:
	packet::MUID uidStage;
	packet::MUID uidChar;
	packet::blob PeerInfo;
	packet::blob KillInfo;

public:
	enum { packetID = 1502 };

	Stage_RoundFinishInfo(packet::MUID uidStage, packet::MUID uidChar, packet::blob PeerInfo, packet::blob KillInfo);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Stage_RoundFinishInfo()
	{
	}

};

}
}
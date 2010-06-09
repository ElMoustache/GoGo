/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <boost/cstdint.hpp>
#include <cockpit/packet/Packet.h>
#include <cockpit/packet/Parameters.h>

namespace cockpit {
namespace packet {
namespace protocol {

// Request Stage List
class Stage_RequestStageList : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidChannel;
	packet::int32 StageCursor;

public:
	enum { packetID = 1311 };

	Stage_RequestStageList(packet::MUID uidPlayer, packet::MUID uidChannel, packet::int32 StageCursor);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_RequestStageList()
	{
	}

};

}
}
}

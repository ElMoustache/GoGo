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

// Queue Info
class Match_Duel_QueueInfo : public Packet
{
private:
	packet::blob QueueInfo;

public:
	enum { packetID = 3100 };

	Match_Duel_QueueInfo(packet::blob QueueInfo);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Duel_QueueInfo()
	{
	}

};

}
}
}

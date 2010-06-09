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

// QuestPing
class Match_Quest_Ping : public Packet
{
private:
	packet::uint32 nTimeStamp;

public:
	enum { packetID = 6012 };

	Match_Quest_Ping(packet::uint32 nTimeStamp);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Quest_Ping()
	{
	}

};

}
}
}

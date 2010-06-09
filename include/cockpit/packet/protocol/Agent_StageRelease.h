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

// Release stage on AgentServer
class Agent_StageRelease : public Packet
{
private:
	packet::MUID StageUID;

public:
	enum { packetID = 5052 };

	Agent_StageRelease(packet::MUID StageUID);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Agent_StageRelease()
	{
	}

};

}
}
}

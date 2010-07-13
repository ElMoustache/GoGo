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

// Let agent to Relay Peer
class Agent_RelayPeer : public Packet
{
private:
	packet::MUID PlayerUID;
	packet::MUID PeerCharUID;
	packet::MUID StageUID;

public:
	enum { packetID = 5062 };

	Agent_RelayPeer(const packet::MUID& PlayerUID, const packet::MUID& PeerCharUID, const packet::MUID& StageUID);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Agent_RelayPeer()
	{
	}

};

}
}
}

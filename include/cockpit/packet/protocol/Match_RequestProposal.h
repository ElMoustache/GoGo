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

// Request Proposal
class Match_RequestProposal : public Packet
{
private:
	packet::MUID uidChar;
	packet::int32 ProposalMode;
	packet::int32 RequestID;
	packet::int32 ReplierCount;
	packet::blob ReplierCharNames;

public:
	enum { packetID = 1561 };

	Match_RequestProposal(packet::MUID uidChar, packet::int32 ProposalMode, packet::int32 RequestID, packet::int32 ReplierCount, packet::blob ReplierCharNames);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestProposal()
	{
	}

};

}
}
}

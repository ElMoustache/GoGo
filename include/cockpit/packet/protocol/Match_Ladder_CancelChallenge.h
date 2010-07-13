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

// Cancel Ladder Challenge
class Match_Ladder_CancelChallenge : public Packet
{
private:
	packet::string CharName;

public:
	enum { packetID = 1576 };

	Match_Ladder_CancelChallenge(const packet::string& CharName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_Ladder_CancelChallenge()
	{
	}

};

}
}
}

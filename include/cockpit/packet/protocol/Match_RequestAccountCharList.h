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

// Request Account Character List
class Match_RequestAccountCharList : public Packet
{
private:
	packet::blob EMsg;

public:
	enum { packetID = 1701 };

	Match_RequestAccountCharList(const packet::blob& EMsg);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestAccountCharList()
	{
	}

};

}
}
}

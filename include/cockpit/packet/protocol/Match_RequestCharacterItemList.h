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

// Request Character Item List
class Match_RequestCharacterItemList : public Packet
{
private:
	packet::MUID uid;

public:
	enum { packetID = 1821 };

	Match_RequestCharacterItemList(const packet::MUID& uid);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestCharacterItemList()
	{
	}

};

}
}
}

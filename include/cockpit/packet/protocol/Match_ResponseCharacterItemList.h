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

// Response Character Item List
class Match_ResponseCharacterItemList : public Packet
{
private:
	packet::int32 Bounty;
	packet::blob EquipItemList;
	packet::blob ItemList;
	packet::blob GambleItemList;

public:
	enum { packetID = 1822 };

	Match_ResponseCharacterItemList(packet::int32 Bounty, packet::blob EquipItemList, packet::blob ItemList, packet::blob GambleItemList);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_ResponseCharacterItemList()
	{
	}

};

}
}
}
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

// Request Shop Item List
class Match_RequestShopItemList : public Packet
{
private:
	packet::MUID uid;
	packet::int32 FirstItemIndex;
	packet::int32 ItemCount;

public:
	enum { packetID = 1815 };

	Match_RequestShopItemList(const packet::MUID& uid, const packet::int32& FirstItemIndex, const packet::int32& ItemCount);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestShopItemList()
	{
	}

};

}
}
}

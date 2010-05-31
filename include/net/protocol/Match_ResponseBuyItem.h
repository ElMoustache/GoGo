/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <net/packet.h>
#include <boost/cstdint.hpp>
#include <net/PacketParameters.h>

namespace packet {
namespace protocol {

// Response Buy Item
class Match_ResponseBuyItem : public Packet
{
private:
	packet::int32 result;

public:
	enum { packetID = 1812 };

	Match_ResponseBuyItem(packet::int32 result);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Match_ResponseBuyItem()
	{
	}

};

}
}
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

// Response sell quest item
class Quest_item_responsesell : public Packet
{
private:
	packet::int32 Result;
	packet::int32 PlayerBounty;

public:
	enum { packetID = 21005 };

	Quest_item_responsesell(const packet::int32& Result, const packet::int32& PlayerBounty);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_item_responsesell()
	{
	}

};

}
}
}

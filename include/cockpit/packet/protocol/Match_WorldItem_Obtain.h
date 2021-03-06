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

// Obtain WorldItem
class Match_WorldItem_Obtain : public Packet
{
private:
	packet::MUID uidChar;
	packet::int32 nItemUID;

public:
	enum { packetID = 1542 };

	Match_WorldItem_Obtain(const packet::MUID& uidChar, const packet::int32& nItemUID);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_WorldItem_Obtain()
	{
	}

};

}
}
}

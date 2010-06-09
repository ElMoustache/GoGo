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

// Request Bring Account Item
class Match_RequestBringAccountItem : public Packet
{
private:
	packet::MUID uidChar;
	packet::int32 AIID;

public:
	enum { packetID = 1833 };

	Match_RequestBringAccountItem(packet::MUID uidChar, packet::int32 AIID);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestBringAccountItem()
	{
	}

};

}
}
}

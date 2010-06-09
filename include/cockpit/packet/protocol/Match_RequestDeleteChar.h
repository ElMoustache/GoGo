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

// Request Delete Character
class Match_RequestDeleteChar : public Packet
{
private:
	packet::MUID uid;
	packet::uint32 CharIndex;
	packet::int32 one;
	packet::string CharName;

public:
	enum { packetID = 1713 };

	Match_RequestDeleteChar(packet::MUID uid, packet::uint32 CharIndex, packet::int32 one, packet::string CharName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_RequestDeleteChar()
	{
	}

};

}
}
}

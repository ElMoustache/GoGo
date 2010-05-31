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

// Request Character Info
class Match_RequestCharInfo : public Packet
{
private:
	packet::MUID uid;
	packet::uint32 CharIndex;

public:
	enum { packetID = 1705 };

	Match_RequestCharInfo(packet::MUID uid, packet::uint32 CharIndex);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Match_RequestCharInfo()
	{
	}

};

}
}
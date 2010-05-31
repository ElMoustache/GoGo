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

// Request Character Info Detail
class Match_RequestCharInfoDetail : public Packet
{
private:
	packet::MUID uid;
	packet::string CharName;

public:
	enum { packetID = 1717 };

	Match_RequestCharInfoDetail(packet::MUID uid, packet::string CharName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Match_RequestCharInfoDetail()
	{
	}

};

}
}
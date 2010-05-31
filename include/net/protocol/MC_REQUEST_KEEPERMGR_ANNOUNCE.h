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

// keeper manager request to keeper do that announce to it's match server
class MC_REQUEST_KEEPERMGR_ANNOUNCE : public Packet
{
private:
	packet::string announce;

public:
	enum { packetID = 31020 };

	MC_REQUEST_KEEPERMGR_ANNOUNCE(packet::string announce);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~MC_REQUEST_KEEPERMGR_ANNOUNCE()
	{
	}

};

}
}
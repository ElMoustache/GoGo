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

// update custom ip.
class MC_LOCAL_UPDAET_CUSTOM_IP : public Packet
{

public:
	enum { packetID = 50008 };

	MC_LOCAL_UPDAET_CUSTOM_IP();

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~MC_LOCAL_UPDAET_CUSTOM_IP()
	{
	}

};

}
}
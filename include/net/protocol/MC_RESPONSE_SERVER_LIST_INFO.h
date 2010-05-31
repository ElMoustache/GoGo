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

// response connectable server list info
class MC_RESPONSE_SERVER_LIST_INFO : public Packet
{
private:
	packet::blob serverlist;

public:
	enum { packetID = 40002 };

	MC_RESPONSE_SERVER_LIST_INFO(packet::blob serverlist);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~MC_RESPONSE_SERVER_LIST_INFO()
	{
	}

};

}
}
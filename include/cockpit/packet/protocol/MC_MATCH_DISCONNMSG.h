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

// disconnect reason
class MC_MATCH_DISCONNMSG : public Packet
{
private:
	packet::uint32 messageid;

public:
	enum { packetID = 1010 };

	MC_MATCH_DISCONNMSG(packet::uint32 messageid);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~MC_MATCH_DISCONNMSG()
	{
	}

};

}
}
}

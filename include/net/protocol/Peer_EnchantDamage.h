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

// EnchantDamage
class Peer_EnchantDamage : public Packet
{
private:
	packet::MUID OwnerUID;
	packet::MUID TargetUID;

public:
	enum { packetID = 10055 };

	Peer_EnchantDamage(packet::MUID OwnerUID, packet::MUID TargetUID);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Peer_EnchantDamage()
	{
	}

};

}
}
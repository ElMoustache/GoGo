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

// Request Takeoff Item
class MatchRequestTakeoffItem : public Packet
{
private:
	packet::MUID uid;
	packet::uint32 EquipmentSlot;

public:
	enum { packetID = 1825 };

	MatchRequestTakeoffItem(const packet::MUID& uid, const packet::uint32& EquipmentSlot);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~MatchRequestTakeoffItem()
	{
	}

};

}
}
}

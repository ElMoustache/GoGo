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

// Send survival result
class Quest_Survival_Result : public Packet
{
private:
	packet::int32 Reachedround;
	packet::int32 Point;

public:
	enum { packetID = 6103 };

	Quest_Survival_Result(packet::int32 Reachedround, packet::int32 Point);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_Survival_Result()
	{
	}

};

}
}
}

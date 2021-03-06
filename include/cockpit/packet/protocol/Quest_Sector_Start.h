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

// Quest Sector Start
class Quest_Sector_Start : public Packet
{
private:
	packet::int8 SectorIndex;
	packet::uint8 RepeatIndex;

public:
	enum { packetID = 6053 };

	Quest_Sector_Start(const packet::int8& SectorIndex, const packet::uint8& RepeatIndex);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Quest_Sector_Start()
	{
	}

};

}
}
}

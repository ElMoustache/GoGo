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

// Report TimeSync for Verify SpeedHack
class Game_ReportTimeSync : public Packet
{
private:
	packet::uint32 LocalTimeStamp;
	packet::uint32 MemoryChecksum;

public:
	enum { packetID = 1523 };

	Game_ReportTimeSync(packet::uint32 LocalTimeStamp, packet::uint32 MemoryChecksum);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Game_ReportTimeSync()
	{
	}

};

}
}
}
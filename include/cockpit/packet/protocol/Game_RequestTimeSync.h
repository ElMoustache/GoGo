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

// Request TimeSync for Game
class Game_RequestTimeSync : public Packet
{
private:
	packet::uint32 LocalTimeStamp;

public:
	enum { packetID = 1521 };

	Game_RequestTimeSync(packet::uint32 LocalTimeStamp);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Game_RequestTimeSync()
	{
	}

};

}
}
}

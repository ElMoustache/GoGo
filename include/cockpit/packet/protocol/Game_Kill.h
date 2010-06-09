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

// Object Die
class Game_Kill : public Packet
{
private:
	packet::MUID Attacker;

public:
	enum { packetID = 1511 };

	Game_Kill(packet::MUID Attacker);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Game_Kill()
	{
	}

};

}
}
}

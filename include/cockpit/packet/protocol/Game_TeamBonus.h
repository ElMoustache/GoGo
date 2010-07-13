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

// Game.TeamBonus
class Game_TeamBonus : public Packet
{
private:
	packet::MUID CharUID;
	packet::uint32 ExpArg;

public:
	enum { packetID = 1517 };

	Game_TeamBonus(const packet::MUID& CharUID, const packet::uint32& ExpArg);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Game_TeamBonus()
	{
	}

};

}
}
}

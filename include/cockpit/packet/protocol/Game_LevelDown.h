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

// Game.LevelDown
class Game_LevelDown : public Packet
{
private:
	packet::MUID Player;
	packet::int32 Level;

public:
	enum { packetID = 1514 };

	Game_LevelDown(const packet::MUID& Player, const packet::int32& Level);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Game_LevelDown()
	{
	}

};

}
}
}

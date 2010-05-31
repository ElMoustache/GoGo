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

// Game.LevelUp
class Game_LevelUp : public Packet
{
private:
	packet::MUID Player;
	packet::int32 Level;

public:
	enum { packetID = 1513 };

	Game_LevelUp(packet::MUID Player, packet::int32 Level);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~Game_LevelUp()
	{
	}

};

}
}
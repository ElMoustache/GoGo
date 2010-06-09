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

// Change Team
class Stage_Team : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidStage;
	packet::uint32 nTeam;

public:
	enum { packetID = 1423 };

	Stage_Team(packet::MUID uidPlayer, packet::MUID uidStage, packet::uint32 nTeam);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_Team()
	{
	}

};

}
}
}

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

// Launch Ladder Game
class Ladder_Launch : public Packet
{
private:
	packet::MUID uidStage;
	packet::string MapName;

public:
	enum { packetID = 1579 };

	Ladder_Launch(packet::MUID uidStage, packet::string MapName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Ladder_Launch()
	{
	}

};

}
}
}
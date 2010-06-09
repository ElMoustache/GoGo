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

// Request Join a Private Stage
class Stage_RequestPrivateJoin : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidStage;
	packet::string Password;

public:
	enum { packetID = 1305 };

	Stage_RequestPrivateJoin(packet::MUID uidPlayer, packet::MUID uidStage, packet::string Password);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_RequestPrivateJoin()
	{
	}

};

}
}
}

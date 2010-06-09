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

// Requst PlayerList from the Stage
class Stage_Request_PlayerList : public Packet
{
private:
	packet::MUID uidStage;

public:
	enum { packetID = 1308 };

	Stage_Request_PlayerList(packet::MUID uidStage);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_Request_PlayerList()
	{
	}

};

}
}
}

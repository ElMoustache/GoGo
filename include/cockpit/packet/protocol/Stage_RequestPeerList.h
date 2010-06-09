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

// Request peer list
class Stage_RequestPeerList : public Packet
{
private:
	packet::MUID uidPlayer;
	packet::MUID uidStage;

public:
	enum { packetID = 1461 };

	Stage_RequestPeerList(packet::MUID uidPlayer, packet::MUID uidStage);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_RequestPeerList()
	{
	}

};

}
}
}

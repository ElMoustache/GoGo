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

// Set Master
class Stage_Master : public Packet
{
private:
	packet::MUID uidStage;
	packet::MUID uidPlayer;

public:
	enum { packetID = 1421 };

	Stage_Master(const packet::MUID& uidStage, const packet::MUID& uidPlayer);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_Master()
	{
	}

};

}
}
}

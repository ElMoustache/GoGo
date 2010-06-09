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

// Response Join a Stage
class Stage_ResponseJoin : public Packet
{
private:
	packet::int32 Result;

public:
	enum { packetID = 1306 };

	Stage_ResponseJoin(packet::int32 Result);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_ResponseJoin()
	{
	}

};

}
}
}

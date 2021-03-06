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

// Require password
class Stage_RequirePassword : public Packet
{
private:
	packet::MUID uidStage;
	packet::string StageName;

public:
	enum { packetID = 1332 };

	Stage_RequirePassword(const packet::MUID& uidStage, const packet::string& StageName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Stage_RequirePassword()
	{
	}

};

}
}
}

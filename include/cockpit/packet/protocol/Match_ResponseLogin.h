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

// Response Login
class Match_ResponseLogin : public Packet
{
private:
	packet::int32 Result;
	packet::string ServerName;
	packet::vector ServerMode;
	packet::string AccountID;
	packet::uint8 UGradeID;
	packet::uint8 PGradeID;
	packet::MUID uidPlayer;
	packet::boolean bEnabledSurvivalMode;
	packet::blob EncryptMsg;

public:
	enum { packetID = 1002 };

	Match_ResponseLogin(packet::int32 Result, packet::string ServerName, packet::vector ServerMode, packet::string AccountID, packet::uint8 UGradeID, packet::uint8 PGradeID, packet::MUID uidPlayer, packet::boolean bEnabledSurvivalMode, packet::blob EncryptMsg);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_ResponseLogin()
	{
	}

};

}
}
}

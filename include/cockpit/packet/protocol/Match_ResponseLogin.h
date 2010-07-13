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
	packet::int8 ServerMode;
	packet::string AccountID;
	packet::uint8 UGradeID;
	packet::uint8 PGradeID;
	packet::MUID uidPlayer;
	packet::blob EncryptMsg;

public:
	enum { packetID = 1002 };

	Match_ResponseLogin(const packet::int32& Result, const packet::string& ServerName, const packet::int8& ServerMode, const packet::string& AccountID, const packet::uint8& UGradeID, const packet::uint8& PGradeID, const packet::MUID& uidPlayer, const packet::blob& EncryptMsg);

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

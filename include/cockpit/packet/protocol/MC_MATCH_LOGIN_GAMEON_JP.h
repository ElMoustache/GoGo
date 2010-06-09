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

// Login from GameOn Japan
class MC_MATCH_LOGIN_GAMEON_JP : public Packet
{
private:
	packet::string szString;
	packet::string szStatIndex;
	packet::int32 CommandVersion;
	packet::uint32 nChecksumPack;
	packet::blob EncryptMD5Value;

public:
	enum { packetID = 1012 };

	MC_MATCH_LOGIN_GAMEON_JP(packet::string szString, packet::string szStatIndex, packet::int32 CommandVersion, packet::uint32 nChecksumPack, packet::blob EncryptMD5Value);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~MC_MATCH_LOGIN_GAMEON_JP()
	{
	}

};

}
}
}

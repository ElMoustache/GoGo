/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <net/packet.h>
#include <boost/cstdint.hpp>
#include <net/PacketParameters.h>

namespace packet {
namespace protocol {

// Request Update Account UGrade
class Admin_RequestUpdateAccountUGrade : public Packet
{
private:
	packet::MUID uidAdmin;
	packet::string uidTargetCharName;

public:
	enum { packetID = 513 };

	Admin_RequestUpdateAccountUGrade(packet::MUID uidAdmin, packet::string uidTargetCharName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;
};

}
}
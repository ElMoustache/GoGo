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

// ChatRoom Chat
class ChatRoom_Chat : public Packet
{
private:
	packet::string ChatRoomName;
	packet::string SenderName;
	packet::string Message;

public:
	enum { packetID = 1662 };

	ChatRoom_Chat(packet::string ChatRoomName, packet::string SenderName, packet::string Message);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	virtual ~ChatRoom_Chat()
	{
	}

};

}
}
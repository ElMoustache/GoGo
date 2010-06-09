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

// Channel List
class Channel_List : public Packet
{
private:
	packet::blob ChannelList;

public:
	enum { packetID = 1213 };

	Channel_List(packet::blob ChannelList);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Channel_List()
	{
	}

};

}
}
}

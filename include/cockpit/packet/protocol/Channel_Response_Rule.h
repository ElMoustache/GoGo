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

// Response the Channel Rule
class Channel_Response_Rule : public Packet
{
private:
	packet::MUID uidChannel;
	packet::string RuleName;

public:
	enum { packetID = 1231 };

	Channel_Response_Rule(const packet::MUID& uidChannel, const packet::string& RuleName);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Channel_Response_Rule()
	{
	}

};

}
}
}

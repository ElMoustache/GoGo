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

// Match Object Cache
class Match_ObjectCache : public Packet
{
private:
	packet::uint8 Type;
	packet::blob ObjectCache;

public:
	enum { packetID = 1101 };

	Match_ObjectCache(packet::uint8 Type, packet::blob ObjectCache);

	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~Match_ObjectCache()
	{
	}

};

}
}
}

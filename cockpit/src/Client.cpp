/**
	http://code.google.com/p/gunzemulator/wiki/RawPacketStructure

	Before reading through this file, you have required reading! You MUST
	read that document, or you can't complain about this file. There's no
	need for more levels of abstraction at this point. Just RTFM.
*/

#include "Client.h"
#include "packet/crypto.h"

#include <boost/asio/read.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace cockpit {

struct Client::PacketHeader
{
	uint16_t version;
	uint16_t fullSize;
	uint16_t checksum;
};

struct Client::Payload
{
	uint16_t dataSize;
	uint16_t commandID;
	uint8_t packetID;

	// We don't care about the parameters.
};

Client::Client(Logger* _logger, ClientHandlerFactory* factory, io_service* io)
	: logger(_logger), handler(factory->create_client_handler()), socket(*io)
{
}

string Client::get_ip() const
{
	try {
		return socket.local_endpoint().address().to_string();
	} catch(system::error_code ec) {
		return "Unknown IP";
	}
}

void Client::start()
{
	try {
		handler->initialize(this, &registry);
		cryptoKey = handler->handshake(socket);

		recieve_packet_header();
	} catch(const std::exception& ex) {
		logger->info(format("[%1%] Connection terminated (%2%).") % get_ip() % ex.what());
	}
}

void Client::recieve_packet_header()
{
	shared_ptr<PacketHeader> p = make_shared<PacketHeader>();

	async_read(socket,
		// Instead of doing sizeof(RawPacket), we just get the packet header so
		// we can drop the payload into an appropriately sized buffer.
		buffer(p.get(), sizeof(PacketHeader)),
		bind(
			&Client::on_packet_header,
			shared_from_this(),
			p,
			_1,
			_2
		)
	);
}

// http://code.google.com/p/gunzemulator/wiki/RawPacketStructure
void Client::decrypt(PacketHeader* p)
{
	// TODO: Decrypt the "fullSize" member.
}

void Client::on_packet_header(
	shared_ptr<PacketHeader> p,	// NOTE: This only fills in the packet header.
	system::error_code err,
	size_t bytesTransferred)
{
	if(err || bytesTransferred != sizeof(PacketHeader))
	{
		logger->info(format("[%1%] Failure in recv(). Terminating the connection.") % get_ip());
		return;
	}

	if(p->version == 0x65)
	{
		logger->debug(format("[%1%] Packet encrypted. Decrypting...") % get_ip());
		decrypt(p.get());
	}

	else if(p->version != 0x64)
		logger->debug(format("[%1%] Unknown protocol version %2% recieved.") % get_ip() % p->version);

	recieve_payload(p->fullSize);
	recieve_packet_header();
}

void Client::recieve_payload(uint16_t fullSize)
{
	uint16_t payloadSize = fullSize - sizeof(PacketHeader);
	shared_array<uint8_t> payload(new uint8_t[payloadSize]);

	async_read(socket,
		buffer(payload.get(), payloadSize),
		bind(
			&Client::on_payload,
			shared_from_this(),
			payload,
			payloadSize,
			_1,
			_2
		)
	);
}

void Client::on_payload(shared_array<uint8_t> payload, boost::uint16_t payloadSize, system::error_code err, size_t bytesTransferred)
{
}

void Client::send(const packet::Packet* packet)
{
	send(packet->serialize());
}

void Client::send(const Buffer& buf)
{
	try {
		socket.send(buffer(buf.data(), buf.length()));
	} catch(system::error_code ec) {
		logger->info(format("Sending to %1% failed (%2%).") % get_ip() % ec.message());
	}
}

Client::~Client()
{
	delete handler;
}

}
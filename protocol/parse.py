#!/usr/bin/python3.1
# -*- coding: iso-8859-1 -*-
# To the poor soul reading through this file to make changes:
# I'm sorry, and good luck. I hope you manage to make this file suck less.
#    - Clark

class Command:
	def __init__(self):
		self.id = ''
		self.name = ''
		self.docstring = ''
		self.parameters = list()

class Parameter:
	def __init__(self):
		self.id = ''
		self.type = ''
		self.name = ''

def clean(commands):
	def get_type(paramID):
		if paramID == 0x00:
			return "boost::int32_t"
		elif paramID == 0x01:
			return "boost::uint32_t"
		elif paramID == 0x02:
			return "float"
		elif paramID == 0x03:
			return "bool"
		elif paramID == 0x04:
			return "const std::string&"
		elif paramID == 0x06:
			return "const boost::array<float, 3>&"
		elif paramID == 0x07:
			return "const boost::array<float, 3>&"
		elif paramID == 0x08:
			return "boost::uint32_t"
		elif paramID == 0x09:
			return "boost::uint64_t"
		elif paramID == 0x0A:
			return "boost::tuple<Buffer /* data */, size_t /* count */, size_t /* size */>"
		elif paramID == 0x0B:
			return "boost::int8_t"
		elif paramID == 0x0C:
			return "boost::uint8_t"
		elif paramID == 0x0D:
			return "boost::int16_t"
		elif paramID == 0x0E:
			return "boost::uint16_t"
		else:
			return None

	to_drop = list()

	for c in commands:
		savedID = c.id
		c.id = int(c.id, 16)
		c.name = ''.join([x for x in c.name if x != ' ']).replace('.', '_')
		# No docstring changes necessary.
		for p in c.parameters:
			p.type = get_type(p.id)
			if p.type == None:
				to_drop.append(c)
			p.name = ''.join([x for x in p.name if x != ' ' if x != ')']).replace('.', '_').replace('(', '_').replace(' ', '_')

		if c.name in [x.name for x in commands if x != c]:
			print("Warning: Conflict found ->", c.name, 'ID:', savedID)

	commands = [c for c in commands if c not in to_drop]

	print("Commands:\n", '\n'.join([''.join([c.name, '(', ' '.join([p.name for p in c.parameters]), ')']) for c in commands]), sep='')

	return commands

def parse(p):
	c = list()
	for x in p:
		if x.find('Command ID = ') == 0:
			c.append(Command())
			c[-1].id = x[x.find(' = ') + 3:]
		elif x.find('Command = ') == 0:
			c[-1].name = x[x.find('"') + 1:-1]
		elif x.find('Command Help = ') == 0:
			c[-1].docstring = x[x.find('"') + 1:-1]
		elif x.find('    Parameter Type = ') == 0:
			c[-1].parameters.append(Parameter())
			c[-1].parameters[-1].id = int(x[x.find(' = ') + 3:], 16)
		elif x.find('    Parameter = ') == 0:
			c[-1].parameters[-1].name = x[x.find('"') + 1:-1]

	return clean(c)

def make_packet_registry_header_header():
	return """/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once
#include <string>
#include <cstddef>
#include <boost/function.hpp>
#include <boost/cstdint.hpp>
#include <boost/array.hpp>
#include <boost/tuple/tuple.hpp>
#include <util/buffer.h>

namespace cockpit {
namespace packet {

// Handles the registration and dispatch to the various packet handlers
// around the nation.
class Registry
{
public:
	Registry();

	void dispatch(boost::uint16_t packetID,
	              const boost::uint8_t* parameters,
	              boost::uint16_t length);

	~Registry();

	/// This function is called whenever a corrupt packet is encountered.
	boost::function<void (boost::uint16_t /* packetID */,
	                      const boost::uint8_t* /* rawParameters */,
	                      boost::uint16_t /* length */)> OnFailedParse;

	/// This function is called whenever a packet has a commandID that hasn't
	/// been enumerated by the protocol.
	boost::function<void (boost::uint16_t /* packetID */)> OnInvalidPacketType;

	/// This function is called whenever a packet has a commandID that hasn't
	/// been hooked yet. This can be noisy while gogo is in development ;)
	boost::function<void (boost::uint16_t /* packetID */)> OnUnimplementedPacket;"""

def make_packet_registry_header_footer():
	return "\n};\n\n}\n}\n"

def build_packet_registry_header(filename, commands):
	f = open(filename, 'w')

	print(make_packet_registry_header_header(), end='', file=f)

	for c in commands:
		print('\n\n\t// ', c.docstring, '\n', sep='', end='', file=f)
		print('\tboost::function<void (', sep='',end='', file=f)
		for p in c.parameters:
			seperator = ''
			if p == c.parameters[0]:
				seperator = ''
			else:
				seperator = ', '

			print(seperator, p.type, ' /* ', p.name, ' */', sep='', end='', file=f)

		print(')> ', c.name, ';', sep='', end='', file=f)

	print(make_packet_registry_header_footer(), end='', file=f)

def make_packet_registry_cpp_header():
	return """/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */

#include <boost/array.hpp>
#include <boost/format.hpp>
#include <boost/bind.hpp>

#include <util/buffer.h>
#include <cockpit/packet/Registry.h>
#include <cockpit/packet/protocol/all>

using namespace std;
using namespace boost;

// The following are implemented in security.cpp
// If they throw ANY exception, the packet's parsing will be broken,
// the packet will be dropped, and OnFailedParse will be signaled.
// The extraction method MUST modify *currentParam to point to the
// next element in the parameter string.
int32_t extract_int32(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
uint32_t extract_uint32(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
float extract_float(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
bool extract_bool(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
string extract_string(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
array<float, 3> extract_position(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
array<float, 3> extract_direction(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
uint32_t extract_color(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
uint64_t extract_MUID(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
tuple<Buffer /* data */, size_t /* count */, size_t /* size */>
extract_blob(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
boost::int8_t extract_int8(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
boost::uint8_t extract_uint8(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
int16_t extract_int16(const uint8_t* paramStart, const uint8_t** currentParam, uint16_t packetLength);
uint16_t extract_uint16(const uint8_t* paramStart, const uint8_t**currentParam, uint16_t packetLength);

namespace cockpit {
namespace packet {

Registry::~Registry()
{
}

namespace {
	// Represents the first parameter to do_nothing_*
	struct nothing_info
	{
		const Registry* self;
		uint16_t packetID;

		nothing_info(const Registry* _self, uint16_t _packetID)
			: self(_self), packetID(_packetID)
		{
		}
	};
}

static void do_nothing_0(nothing_info info)
{
	if(info.packetID && info.self->OnUnimplementedPacket)
		info.self->OnUnimplementedPacket(info.packetID);
}

template <typename T1>
static void do_nothing_1(nothing_info info, T1) { return do_nothing_0(info); }
template <typename T1, typename T2>
static void do_nothing_2(nothing_info info, T1, T2) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3>
static void do_nothing_3(nothing_info info, T1, T2, T3) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4>
static void do_nothing_4(nothing_info info, T1, T2, T3, T4) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4, typename T5>
static void do_nothing_5(nothing_info info, T1, T2, T3, T4, T5) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
static void do_nothing_6(nothing_info info, T1, T2, T3, T4, T5, T6) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
static void do_nothing_7(nothing_info info, T1, T2, T3, T4, T5, T6, T7) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
static void do_nothing_8(nothing_info info, T1, T2, T3, T4, T5, T6, T7, T8) { return do_nothing_0(info); }
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
static void do_nothing_9(nothing_info info, T1, T2, T3, T4, T5, T6, T7, T8, T9) { return do_nothing_0(info); }
"""

def make_packet_registry_constructor(commands):
	ret =  """
Registry::Registry()
	:
	OnFailedParse(bind(do_nothing_3<uint16_t, const uint8_t*, uint16_t>, nothing_info(this, 0), _1, _2, _3)),
	OnInvalidPacketType(bind(do_nothing_1<uint16_t>, nothing_info(this, 0), _1)),
	OnUnimplementedPacket(bind(do_nothing_1<uint16_t>, nothing_info(this, 0), _1)),
	"""

	def make_params(command):
		return ', '.join([p.type for p in command.parameters])

	# Don't even TRY to understand this function :( My head hurts.
	def make_command_string(command):
		return ''.join([
			command.name,
			'(bind(do_nothing_', str(len(command.parameters)),
			((''.join(['< ', make_params(command), ' >'])) if len(command.parameters) != 0 else ''),
			''.join([', nothing_info(this, ', str(command.id), ')']),
			(''.join([', ', ', '.join([''.join(["_", str(x + 1)]) for x in range(len(command.parameters))])]) if len(command.parameters) != 0 else ''),
			'))'
		])

	ret = ''.join([ret, ',\n\t'.join([make_command_string(s) for s in commands])])

	ret = ''.join([ret, '\n{\n}\n'])

	return ret

def make_packet_registry_cpp_footer():
	return "\n\n}\n}\n"

def make_packet_registry_functions(commands):
	extractorMap = {
		0x00 : ("int32_t", "extract_int32"),
		0x01 : ("uint32_t", "extract_uint32"),
		0x02 : ("float", "extract_float"),
		0x03 : ("bool", "extract_bool"),
		0x04 : ("std::string", "extract_string"),
		0x06 : ("array<float, 3>", "extract_position"),
		0x07 : ("array<float, 3>", "extract_direction"),
		0x08 : ("uint32_t", "extract_color"),
		0x09 : ("uint64_t", "extract_MUID"),
		0x0A : ("tuple<Buffer, size_t, size_t>", "extract_blob"),
		0x0B : ("int8_t", "extract_int8"),
		0x0C : ("uint8_t", "extract_uint8"),
		0x0D : ("int16_t", "extract_int16"),
		0x0E : ("uint16_t", "extract_uint16")
	}

	def make_parameter_name(default, packetParameters):
		if len(packetParameters) > 0:
			return default
		else:
			return ''

	ret = ""

	for c in commands:
		ret = ''.join([ret, '\n\nstatic void do_', c.name, '(Registry* self, const uint8_t*',
			make_parameter_name(" parameters", c.parameters),
			", uint16_t", make_parameter_name(" length", c.parameters),
			")\n{\n", make_parameter_name("\tconst uint8_t* paramPtr = parameters;\n\n", c.parameters)])

		for (p, i) in zip(c.parameters, range(9999999)):
			(type, func) = extractorMap[p.id]
			ret = ''.join([ret, '\t', type, ' p', str(i), ' = ', func, '(parameters, &paramPtr, length);\n'])

		if len(c.parameters) > 0:
			ret = ''.join([ret, '\n'])

		ret = ''.join([ret, '\tself->', c.name, '('])

		for (p, i) in zip(c.parameters, range(9999999)):
			sep = ''
			if i == 0:
				sep = ''
			else:
				sep = ', '

			ret = ''.join([ret, sep, 'p', str(i)])

		ret = ''.join([ret, ');', '\n}'])

	return ret

def make_dispatch(commands):
	ret = """\n\nvoid Registry::dispatch(uint16_t packetID,
                              const uint8_t* parameters,
                              uint16_t length)
{
	try {
		switch(packetID)
		{"""

	for c in commands:
		ret = ''.join([ret, '\n\t\t\tcase protocol::', c.name, '::packetID: return do_', c.name, '(this, parameters, length);'])

	ret = ''.join([ret, '\n\t\t\tdefault: return this->OnInvalidPacketType(packetID);\n\t\t}\n\t} catch(...) {\n\t\tthis->OnFailedParse(packetID, parameters, length);\n\t}\n}'])

	return ret

def build_packet_registry_cpp(filename, commands):
	f = open(filename, 'w')

	print(make_packet_registry_cpp_header(), end='', file=f)
	print(make_packet_registry_constructor(commands), end='', file=f)
	print(make_packet_registry_functions(commands), end='', file=f)
	print(make_dispatch(commands), end='', file=f)
	print(make_packet_registry_cpp_footer(), end='', file=f)

def make_all_packet_types_header_header():
	return """/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#pragma once

"""


def build_all_packet_types_header(filename, commands):
	f = open(filename, 'w')

	print(make_all_packet_types_header_header(), end='', file=f)

	for c in commands:
		print('#include "', c.name, '.h"\n', sep='', end='', file=f)

def make_command_header(name, docstring):
	return ''.join(["""/*
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

// """, docstring, """
class """, name, """ : public Packet
{
"""])

def make_local_vars(params):
	retVal = ""

	if len(params) != 0:
		retVal = 'private:\n'

	for p in params:
		retVal = ''.join([retVal, '\t', typeMap[p.id], ' ', p.name, ';\n'])

	return retVal

def make_constructor(command):
	retVal = ''.join(["""\npublic:
	enum { packetID = """, str(command.id), """ };\n\n"""])

	retVal = ''.join([retVal, '\t', command.name, '('])

	for p in command.parameters:
		sep = ', '
		if p == command.parameters[0]:
			sep = ''
		retVal = ''.join([retVal, sep, typeMap[p.id], ' ', p.name])

	retVal = ''.join([retVal, ');\n'])

	return retVal

def make_command_header_footer(commandName):
	return ''.join(["""
	const char* name() const;
	const char* doc() const;
	boost::uint16_t id() const;
	Buffer serialize() const;

	~""", commandName, """()
	{
	}

};

}
}
}
"""])

typeMap = {
	0x00 : "packet::int32",
	0x01 : "packet::uint32",
	0x02 : "packet::floating_point",
	0x03 : "packet::boolean",
	0x04 : "packet::string",
	0x06 : "packet::position",
	0x07 : "packet::direction",
	0x08 : "packet::color",
	0x09 : "packet::MUID",
	0x0A : "packet::blob",
	0x0B : "packet::int8",
	0x0C : "packet::uint8",
	0x0D : "packet::int16",
	0x0E : "packet::uint16"
}

def build_command_header(filename, command):
	f = open(filename, 'w')

	print(make_command_header(command.name, command.docstring), end='', sep='', file=f)
	print(make_local_vars(command.parameters), end='', sep='', file=f)
	print(make_constructor(command), end='', sep='', file=f)
	print(make_command_header_footer(command.name), end='', sep='', file=f)

def make_all_packets_cpp_header():
	return """/*
 * NOTICE: Do not manually edit this file. It has been autogenerated by
 * protocol/parse.py. Any changes should me made there, instead of here.
 */
#include <cockpit/packet/protocol/all>
#include <util/memory.h>

using namespace boost;

#define countof(array) \
	(sizeof(array)/sizeof((array)[0]))

static Buffer merge_parameters(Buffer* serializedParameters, size_t numberOfParameters)
{
	size_t packetLength = 0;

	for(size_t i = 0; i < numberOfParameters; ++i)
		packetLength += serializedParameters[i].length();

	assert(packetLength <= 0xFFFF);

	Buffer out(packetLength);
	uint8_t* outPtr = out.data();
	Buffer* param = serializedParameters;

	for(size_t i = 0; i < numberOfParameters; ++i, ++param)
		outPtr = memory::pcopy(outPtr, param->data(), param->length());

	return out;
}

namespace cockpit {
namespace packet {
namespace protocol {"""

def flesh_out_command(command):
	ret = '\n\n'

	ret = ''.join([ret, command.name, '::', command.name, '('])

	if len(command.parameters) != 0:
		for p in command.parameters:
			sep = ', '
			if p == command.parameters[0]:
				sep = ''
			ret = ''.join([ret, sep, typeMap[p.id], ' _', p.name])

		ret = ''.join([ret, ')\n\t: '])

		for p in command.parameters:
			sep = ', '
			if p == command.parameters[0]:
				sep = ''
			ret = ''.join([ret, sep, p.name, '(_', p.name, ')'])
	else:
		ret = ''.join([ret, ')'])

	ret = ''.join([
		ret,
		'\n{\n}\n\nconst char* ', command.name, '::name() const\n{\n\treturn "',
		command.name, '";\n}\n\nconst char* ', command.name, '::doc() const\n{\n\treturn "',
		command.docstring, '";\n}\n\nuint16_t ', command.name, '::id() const\n{\n\treturn ',
		'packetID', ';\n}\n\nBuffer ', command.name, '::serialize() const\n{\n'])

	if len(command.parameters) != 0:
		ret = ''.join([ret, '\tBuffer serializedParameters[] = {\n'])
		for p in command.parameters:
			sep = ','
			if p == command.parameters[-1]:
				sep = ''
			ret = ''.join([ret, '\t\t', p.name, '.serialize()', sep, '\n'])

		return ''.join([ret, '\t};\n\n', '\treturn merge_parameters(serializedParameters, countof(serializedParameters));\n}'])
	else:
		return ''.join([ret, '\treturn Buffer(0);\n}'])

def make_all_packets_cpp_footer():
	return """

}
}
}
"""

def build_all_packets_cpp(filename, commands):
	f = open(filename, 'w')

	print(make_all_packets_cpp_header(), end='', file=f)
	for c in commands:
		print(flesh_out_command(c), end='', file=f)

	print(make_all_packets_cpp_footer(), end='', file=f)

def make_lookup_header():
	return """#include <cockpit/packet/Lookup.h>
#include <cockpit/packet/protocol/all>

using namespace boost;

namespace cockpit {
namespace packet {

PacketInfo::PacketInfo(const char* _name, const char* _doc, uint16_t _commandID)
	: name(_name), doc(_doc), commandId(_commandID)
{
}

PacketInfo::~PacketInfo()
{
}

BadCommandId::BadCommandId(uint16_t _commandId)
	: std::runtime_error("Bad command ID!"), commandId(_commandId)
{
}

BadCommandId::~BadCommandId() throw()
{
}

PacketInfo lookup(uint16_t commandID)
{
	switch(commandID)
	{
\t\t"""

def make_lookup_command(command):
	return 'case protocol::%s::packetID: return PacketInfo("%s", "%s", commandID);' % (command.name, command.name, command.docstring)

def make_lookup_footer():
	return """
		default: throw BadCommandId(commandID);
	}
}

}
}
"""

def build_lookup(filename, commands):
	f = open(filename, 'w')

	print(make_lookup_header(), end='', file=f)
	print('\n\t\t'.join([make_lookup_command(c) for c in commands]), end='', file=f)
	print(make_lookup_footer(), end='', file=f)

commands = list()

from sys import argv

if len(argv) == 2:
	commands = parse([x[:-1] for x in open(argv[1]).readlines()])
	build_packet_registry_header("include/cockpit/packet/Registry.h", commands)
	build_packet_registry_cpp("cockpit/src/packet/Registry.cpp", commands)
	build_all_packet_types_header("include/cockpit/packet/protocol/all", commands)
	for c in commands:
		build_command_header(''.join(["include/cockpit/packet/protocol/", c.name, '.h']), c)
	build_all_packets_cpp("cockpit/src/packet/all_packets.cpp", commands)
	build_lookup("cockpit/src/packet/lookup.cpp", commands)
else:
	print('Usage: "./parse.py [protocol file]"')
	print("Please note that the build files will be generated in subdirectories of parse.py.")

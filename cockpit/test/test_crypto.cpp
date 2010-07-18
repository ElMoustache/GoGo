#include <gtest/gtest.h>
#include "array_check.h"

#include "../src/packet/crypto.h"

using namespace std;
using namespace boost;
using namespace cockpit::packet;

// Yes, that's PI. Got a problem with that?
static const uint8_t key[] = {
	0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
	0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95,
	0x02, 0x88, 0x41, 0x97, 0x16, 0x93, 0x99, 0x37,
	0x51, 0x05, 0x82, 0x09, 0x74, 0x94, 0x45, 0x92
};

TEST(encryption, single_stage)
{
	uint8_t toEncrypt[] = {
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88
	};

	uint8_t expected[] = {
		0xF4, 0x9C, 0xBD, 0xBC, 0x30, 0x37, 0xEC, 0x93
	};

	encrypt(toEncrypt, sizeof(toEncrypt), 0, key);

	check_arrays(expected, toEncrypt);
}

TEST(encryption, multi_stage)
{
	uint8_t toEncrypt[] = {
		0x11, 0x22, 0x33,   // Encrypted first
		0x44, 0x55,         // Skipped
		0x66, 0x77, 0x88    // Encrypted last
	};

	uint8_t expected[] = {
		0xF4, 0x9C, 0xBD,   // Encrypted first
		0x44, 0x55,         // Skipped
		0x37, 0xEC, 0x93    // Encrypted last
	};

	encrypt(toEncrypt    , 3, 0, key);
	encrypt(toEncrypt + 5, 3, 5, key);

	check_arrays(expected, toEncrypt);
}

TEST(encryption, long)
{
	// The decimal part of "e" directly in hex. (2.718281...)
	uint8_t toEncrypt[] = {
		0x71, 0x82, 0x81, 0x82, 0x84, 0x59, 0x04, 0x52,
		0x35, 0x36, 0x02, 0x87, 0x47, 0x13, 0x52, 0x66,
		0x24, 0x97, 0x75, 0x72, 0x47, 0x09, 0x36, 0x99,
		0x95, 0x95, 0x74, 0x96, 0x69, 0x67, 0x62, 0x77,
		0x24, 0x07, 0x66, 0x30, 0x35, 0x35, 0x47, 0x59,
		0x45, 0x71, 0x38, 0x21, 0x78, 0x52, 0x51, 0x66,
		0x42, 0x74, 0x27, 0x46, 0x63, 0x91, 0x93, 0x20,
		0x03, 0x05, 0x99, 0x21, 0x81, 0x74, 0x13, 0x59
	};


	uint8_t expected[] = {
		0xF8, 0x88, 0xEB, 0x64, 0x0A, 0xD0, 0x82, 0xC8,
		0x32, 0xA6, 0xFC, 0x8C, 0x7E, 0xE2, 0x5E, 0x8E,
		0x34, 0x13, 0x76, 0x4C, 0xDA, 0xA3, 0x05, 0x25,
		0x68, 0xE2, 0x2E, 0x03, 0x53, 0x8E, 0x14, 0x4C,
		0x52, 0x38, 0x17, 0x32, 0x3C, 0x5D, 0xEA, 0xA9,
		0x3C, 0x4E, 0xBB, 0x58, 0x99, 0xCA, 0x3E, 0x8E,
		0xF8, 0x6F, 0x3C, 0xCA, 0x5E, 0xB0, 0xB1, 0x12,
		0xBA, 0xF0, 0x93, 0xF5, 0x4E, 0xEC, 0x3A, 0x89
	};

	encrypt(toEncrypt, sizeof(toEncrypt), 0, key);

	check_arrays(expected, toEncrypt);
}

TEST(decryption, single_stage)
{
	uint8_t toDecrypt[] = {
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88
	};

	uint8_t expected[] = {
		0x3E, 0xD7, 0x47, 0x83, 0x7E, 0xEC, 0xAB, 0x50
	};

	decrypt(toDecrypt, sizeof(toDecrypt), 0, key);

	check_arrays(expected, toDecrypt);
}

TEST(decryption, multi_stage)
{
	uint8_t toDecrypt[] = {
		0x11, 0x22, 0x33,
		0x44, 0x55,
		0x66, 0x77, 0x88
	};

	uint8_t expected[] = {
		0x3E, 0xD7, 0x47,  // First decrypted.
		0x44, 0x55,        // Skipped.
		0xEC, 0xAB, 0x50   // Last decrypted.
	};

	decrypt(toDecrypt    , 3, 0, key);
	decrypt(toDecrypt + 5, 3, 5, key);

	check_arrays(expected, toDecrypt);
}

TEST(decryption, long)
{
	// This data set is the same that is output during test_long_encryption.
	// Therefore, this tests not only the decryption algorithm, but that it
	// is the inverse of the encryption algorithm.
	uint8_t toDecrypt[] = {
		0xF8, 0x88, 0xEB, 0x64, 0x0A, 0xD0, 0x82, 0xC8,
		0x32, 0xA6, 0xFC, 0x8C, 0x7E, 0xE2, 0x5E, 0x8E,
		0x34, 0x13, 0x76, 0x4C, 0xDA, 0xA3, 0x05, 0x25,
		0x68, 0xE2, 0x2E, 0x03, 0x53, 0x8E, 0x14, 0x4C,
		0x52, 0x38, 0x17, 0x32, 0x3C, 0x5D, 0xEA, 0xA9,
		0x3C, 0x4E, 0xBB, 0x58, 0x99, 0xCA, 0x3E, 0x8E,
		0xF8, 0x6F, 0x3C, 0xCA, 0x5E, 0xB0, 0xB1, 0x12,
		0xBA, 0xF0, 0x93, 0xF5, 0x4E, 0xEC, 0x3A, 0x89
	};

	// The decimal part of "e" directly in hex. (2.718281...)
	uint8_t expected[] = {
		0x71, 0x82, 0x81, 0x82, 0x84, 0x59, 0x04, 0x52,
		0x35, 0x36, 0x02, 0x87, 0x47, 0x13, 0x52, 0x66,
		0x24, 0x97, 0x75, 0x72, 0x47, 0x09, 0x36, 0x99,
		0x95, 0x95, 0x74, 0x96, 0x69, 0x67, 0x62, 0x77,
		0x24, 0x07, 0x66, 0x30, 0x35, 0x35, 0x47, 0x59,
		0x45, 0x71, 0x38, 0x21, 0x78, 0x52, 0x51, 0x66,
		0x42, 0x74, 0x27, 0x46, 0x63, 0x91, 0x93, 0x20,
		0x03, 0x05, 0x99, 0x21, 0x81, 0x74, 0x13, 0x59
	};

	decrypt(toDecrypt, sizeof(toDecrypt), 0, key);

	check_arrays(expected, toDecrypt);
}

TEST(checksum, acceptance)
{
	uint8_t toChecksum[] = {
		0x71, 0x82, 0x81, 0x82, 0x84, 0x59, 0x04, 0x52,
		0x35, 0x36, 0x02, 0x87, 0x47, 0x13, 0x52, 0x66,
		0x24, 0x97, 0x75, 0x72, 0x47, 0x09, 0x36, 0x99,
		0x95, 0x95, 0x74, 0x96, 0x69, 0x67, 0x62, 0x77,
		0x24, 0x07, 0x66, 0x30, 0x35, 0x35, 0x47, 0x59,
		0x45, 0x71, 0x38, 0x21, 0x78, 0x52, 0x51, 0x66,
		0x42, 0x74, 0x27, 0x46, 0x63, 0x91, 0x93, 0x20,
		0x03, 0x05, 0x99, 0x21, 0x81, 0x74, 0x13, 0x59
	};

	uint16_t value = checksum(toChecksum, sizeof(toChecksum));

	EXPECT_EQ(0x104C, value);
}

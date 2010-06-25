#include <database/MySQLGunzDB.h>

#include <cstddef>
#include <cassert>

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>

using namespace std;
using namespace boost;
using namespace mysqlpp;

Query make_get_character_info_query(Connection& c, uint32_t aid, uint8_t marker)
{
	Query q = c.query();
	q << "SELECT * FROM `character` WHERE accountid=" << aid << " AND marker=" << static_cast<uint32_t>(marker);
	return q;
}

// Gets everything but the clan info, equipment, and inventory!
CharacterInfo handle_get_character_info(const StoreQueryResult& result, uint8_t marker)
{
	size_t rowCount = result.num_rows();
	assert(rowCount < 2);

	if(rowCount == 0)
		throw InvalidCharacterInfo();

	const Row& row = result[0];
	CharacterInfo charInfo;

	charInfo.CharacterId = row["id"];
	charInfo.CharacterMarker = marker;
	charInfo.CharacterName = string(row["name"]);
	charInfo.ClanId = row["clanid"];
	charInfo.CharacterLevel = row["level"];
	charInfo.CharacterSex = row["sex"];
	charInfo.CharacterHair = row["hair"];
	charInfo.CharacterFace = row["face"];
	charInfo.CharacterXP = row["xp"];
	charInfo.CharacterBP = row["bp"];

	return charInfo;
}

Query make_get_clan_info_query(Connection& c, uint32_t clanId)
{
	Query q = c.query();
	q << "SELECT * FROM clan WHERE id=" << clanId;
	return q;
}

void handle_clan_info(const StoreQueryResult& result, CharacterInfo* charInfo /* [out] */)
{
	size_t rowCount = result.num_rows();
	assert(rowCount < 2);

	const Row& row = result[0];

	if(rowCount == 1)
	{
		charInfo->ClanName = string(row["name"]);
		charInfo->ClanPoints = row["cwpoints"];
	}
}

CharacterInfo MySQLGunzDB::GetCharacterInfo(uint32_t aid, uint8_t slot)
{
	// Normal, clan, equip, inventory.
	CharacterInfo ret = run_query<CharacterInfo>(
		bind(make_get_character_info_query, _1, aid, static_cast<uint32_t>(slot)),
		bind(handle_get_character_info, _1, slot)
	);

	run_query<void>(
		bind(make_get_clan_info_query, _1, ret.ClanId),
		bind(handle_clan_info, _1, &ret)
	);

	ret.Equipment = GetEquipment(ret.CharacterId);
	ret.Inventory = GetInventory(ret.CharacterId);

	return ret;
}
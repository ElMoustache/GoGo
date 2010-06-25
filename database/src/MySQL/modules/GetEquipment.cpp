#include <database/MySQLGunzDB.h>

#include <cstddef>
#include <cassert>

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>

using namespace std;
using namespace boost;
using namespace mysqlpp;

static Query make_get_equipment_query(Connection& c, uint32_t cid)
{
	Query q = c.query();
	q << "SELECT * from character_equip where charid=" << cid;
	return q;
}

static SmallVector<Item, 12> handle_get_equipment(const StoreQueryResult& result)
{
	size_t rowCount = result.num_rows();
	assert(rowCount < 2);

	SmallVector<Item, 12> ret;

	if(rowCount == 0)
		return ret;

	const Row& row = result[0];

	Item temp;
	for(size_t i = 1, size = row.size(); i < size; ++i)
	{
		temp.ItemCID = row[i];
		ret.push_back(temp);
	}

	return ret;
}

SmallVector<Item, 12> MySQLGunzDB::GetEquipment(uint32_t cid)
{
	return run_query<SmallVector<Item, 12> >(
		bind(make_get_equipment_query, _1, cid),
		handle_get_equipment
	);
}
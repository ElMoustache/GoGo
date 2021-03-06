#include <gunz/detail/PlayerList.h>

#include <climits>

namespace gunz {
namespace detail {

boost::uint8_t PlayerList::Length() const
{
	const size_t realLength = Collection<Player*, std::vector<Player*> >::Length();

	if(realLength <= UCHAR_MAX)
		return realLength;
	else
		return UCHAR_MAX;
}

}
}

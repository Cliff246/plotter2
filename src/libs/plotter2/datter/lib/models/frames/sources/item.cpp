#include "item.hpp"

using namespace datter;



bool item::change_lock(int64_t lockkey, int64_t keyset)
{
	if(m_lockkey == lockkey)
	{
		m_lockkey = keyset;
		return true;
	}
	return false;
}



int64_t item::get_lock() const
{
	return m_lockkey;
}

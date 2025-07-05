#include "item_dictionary.hpp"
#include <_stdlib.h>
#include <algorithm>
#include <string>
#include <utility>
#include <random>

using namespace datter;

//TODO this is missing a huge thing
//that being you cannot define multiple items per key.

item_dictionary::item_dictionary()
{
	return;
}
		
std::string item_dictionary::get_name(int64_t framekey)
{
	//has name recognized
	if(m_overlapping_names.contains(framekey))
	{
		//
		int64_t dest = m_overlapping_names[framekey];
		if(m_to_remove.contains(dest))
		{
			m_overlapping_names.erase(framekey);
			return "";
		}
		else
		{
			//expects it to be there
			return m_names_exposed[dest];
		}	
	}
	else
	{
		return "";
	}
}


static int64_t hash_name(std::string name)
{
	static std::hash<std::string> hasher;

	return static_cast<int64_t>(hasher(name));
}

int64_t item_dictionary::get_random_number()
{
	bool keep_going = true;
	int64_t rand = 0;
	while(keep_going)
	{
		rand = std::rand();
		if(!m_names_exposed.contains(rand))
		{
				keep_going = false;
		}
	}
	return rand;
}
//WILL NOT ALLOW DUPLICATE NAMES WITH THE SAME ID
//can do damage to existing names... don't do to many
bool item_dictionary::add_name(int64_t key, std::string exposed)
{
	int64_t hash = item_dictionary::hash_name(exposed);
	int length = m_name_hashes.size();
	if(length <= 0)
	{
		auto pair = std::make_pair(hash, key);
		m_name_hashes.push_back(pair);
		int64_t rand = get_random_number();		
		m_names_exposed[rand]= exposed;
		m_overlapping_names[key] = rand;

		return true;
	}
	int64_t low = m_name_hashes[0].first, high = m_name_hashes[length - 1].first == 0; 
	bool found = false;
	int64_t dest = 0;
	while(low <= high)
	{
		int64_t mid = low + (high - low) / 2;
		if(m_name_hashes[mid].first == hash)
		{
			found = true;
			dest = mid;
			break;
		}	
		if(m_name_hashes[mid].first < hash)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if(found)
	{
		
		//wtf... this is a hash... we don't want to find it...
		auto pos = m_name_hashes.begin() + dest - 1;

		m_overlapping_names[key] = dest ;
		return false;
	}
	else
	{
		auto pair = std::make_pair(hash, key);
		//put behind
		if(dest < hash)
		{

			if(length == 1)
			{
				dest = 0;
			}	
			auto pos = m_name_hashes.begin() + dest - 1;
			m_name_hashes.insert(pos, pair);
		}
		//put infront
		else
		{	
			auto pos = m_name_hashes.begin() + dest;
			m_name_hashes.insert(pos, pair);
		}
		//add to layers and put in a random spot	
		int64_t random = get_random_number();
		m_names_exposed[random]= exposed;
		m_overlapping_names[key] = random;

		return true;
	}
}

std::string item_dictionary::copy_name(int64_t key, int64_t newkey)
{

}

void item_dictionary::delete_name(std::string name)
{

}

void item_dictionary::delete_key(int64_t)
{

}

void item_dictionary::clean()
{

}


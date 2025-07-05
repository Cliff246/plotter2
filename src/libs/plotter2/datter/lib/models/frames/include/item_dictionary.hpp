#pragma once
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>

namespace datter
{
	class item_dictionary
	{
	private:
		//condenced version
		//contains a 'fake' key
		std::map<int64_t, std::string> m_names_exposed;
		//contains the actual keys to fake key's
		std::map<int64_t, int64_t> m_overlapping_names;

		//contains the hashes to the actual original name token
		std::vector<std::pair<int64_t, int64_t>> m_name_hashes;
		//contains the key's to remove
		std::set<int64_t> m_to_remove;	
		//test on change
		bool m_has_changed;
		static int64_t hash_name(std::string name);

		int64_t get_random_number();
	public:
		
		
		item_dictionary();
		
		std::string get_name(int64_t key);
		bool add_name(int64_t key, std::string exposed);
		std::string copy_name(int64_t key, int64_t newkey);

		void delete_name(std::string name);
		void delete_key(int64_t); 

		void clean();
	};
}

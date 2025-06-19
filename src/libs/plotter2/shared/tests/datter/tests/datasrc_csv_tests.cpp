
#include "datasrc_csv_tests.hpp"


#include "datasrc_csv.hpp"
#include "dataholders/dataholder_string.hpp"
#include "datter_tests.hpp"

#include <vector>


int csv_test1()
{
	plt_shared::datasrc_csv csv;
	std::filesystem::path path("resources/csv1.csv");
	
	csv.set_file(path);	
	std::vector<std::vector<plt_shared::datahold_ptr>> results = csv.get_data();
	
	const std::string data[] = {
		"hello",
		"this",
		"is",
		"a",
		"dumb",
		"file"
	};	
	bool valid = false;
	int needed = 0;
	for(int i = 0; i < results[0].size(); ++i)
	{
		plt_shared::datahold_ptr holder = results[0][i];
		plt_shared::dataholder::datahold_string *str = dynamic_cast<plt_shared::dataholder::datahold_string*>(&*holder);
		std::string string = str->get_string();
		std::cerr << string << "\n";
		if(!data[i].compare(string))
		{
			needed++;
		}	

	}	
	if(needed == 6)
		valid = true;
	return valid;
}


TEST(datter_tests, csv_test1) {
	EXPECT_EQ(csv_test1(), 1); 
}

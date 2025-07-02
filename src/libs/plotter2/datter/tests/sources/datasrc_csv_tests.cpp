
#include "datasrc_csv_tests.hpp"


#include "datasrc_csv.hpp"
#include "dataholders/dataholder_string.hpp"
#include "datter_tests.hpp"

#include <stdexcept>
#include <vector>


int csv_test1()
{
	datter::datasrc_csv csv;
	std::filesystem::path path("resources/csv1.csv");
	
	csv.set_file(path);	
	std::vector<std::vector<datter::datahold_ptr>> results = csv.get_data();
	
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
		datter::datahold_ptr holder = results[0][i];
		datter::dataholder::datahold_string *str = dynamic_cast<datter::dataholder::datahold_string*>(&*holder);
		std::string string = str->get_string();
		if(!data[i].compare(string))
		{
			needed++;
		}	

	}	
	if(needed == 6)
		valid = true;
	return valid;
}

int csv_test2()
{
	datter::datasrc_csv csv;
	std::filesystem::path path("resources/csv2.csv");
	
	csv.set_file(path);	
	std::vector<std::vector<datter::datahold_ptr>> results = csv.get_data();


	const std::vector<std::vector<std::string>> expected = {
// Row 1 (header)
		{"Year", "Make", "Model", "Description", "Price"},
		// Row 2
		{"1997", "Ford", "E350", "ac, abs, moon", "3000.00"},
		// Row 3
		{"1999", "Chevy", "Venture \"Extended Edition\"", "\"\"", "4900.00"},

		// Row 4
		{"1999", "Chevy", "Venture \"Extended Edition, Very Large\"", "\"\"", "5000.00"},

    	// Row 5 (multiline Description)
		{"1996", "Jeep", "Grand Cherokee",
		"MUST SELL!\nair, moon roof,\nloaded", "4799.00"},

		// Row 6 (multiline Description)
		{"2000", "Toyota", "Corolla",
     	"This is a\nmultiline\ndescription", "3200.00"},
		// Row 7 (multiline Description)
		{"2001", "Honda", "Civic",
    	"Runs well.\nHas new brakes and \ntires installed.", "2700.00"},

		// Row 8 (escaped quote, multiline)
		{"2002", "BMW", "320i",
		"\"Special\" edition,\nincludes sunroof", "7800.00"},
	};
	bool valid = true;
	int n = 0, c = 0;
	for(const auto &i : results)
	{
		if(n > expected.size())
		{
			throw std::runtime_error("n > size");	

		}
		for(const auto &k : i)
		{
			if(c > expected[n].size())
			{
				throw std::runtime_error("c > size");
			}
		
			datter::datahold_ptr holder = k;

			if(holder == nullptr)
			{
				throw std::runtime_error("shared pointer held onto null");
			}
			datter::dataholder::datahold_string *str = dynamic_cast<datter::dataholder::datahold_string*>(&*holder);
			
			if(!str)
			{
				throw std::runtime_error("dynamic cast to datahold_string failed");
			}			
			std::string string = str->get_string();
			if(string.c_str() == nullptr)
			{
				throw std::runtime_error("get string returned a failed ptr");
			}
			
			if(expected[n][c].compare(string))
			{
				std::cerr << "compared: " << string << "\n"; 
				std::cerr << "expected: " << expected[n][c] << "\n";
				valid = false;	
			}


			c++;
		}	
		c = 0;
		n++;
	}
	return valid;
}

TEST(datter_tests, csv_test1) {
	EXPECT_EQ(csv_test1(), 1); 
}

TEST(datter_tests, csv_test2) {

	EXPECT_EQ(csv_test2(), 1); 
}

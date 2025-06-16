#include "tests_manager.hpp"
#include "file_manager.hpp"
#include "manager.hpp"
#include <string>


int test_manager_1()
{
	std::string name = "manager1";
	std::string buf = "resources";
	std::filesystem::path path(buf);
	plt_manager::manager manager(name, path);	
	return manager.get_manifest()->validate_manifest();

}

TEST(manager_tests, manager) {
	EXPECT_EQ(test_manager_1(), 1);
}

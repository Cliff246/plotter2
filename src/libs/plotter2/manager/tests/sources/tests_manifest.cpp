
#include <iostream>
#include <Python.h>
#include <filesystem>
#include "manifest.hpp"
#include <gtest/gtest.h>

int test_manifest_1(std::string fp)
{
	std::string buf = fp;
	std::filesystem::path path(buf);
	plt_manager::manifest *json_manifest = new plt_manager::manifest(path);
	json_manifest->load_manifest();
	bool validated = json_manifest->validate_manifest();
	return validated; 
}


TEST(manager_tests, manifest) {
	EXPECT_EQ(test_manifest_1("resources/test1.json"), 1);
	EXPECT_EQ(test_manifest_1("resources/test2.json"), 0);
}


#include <iostream>
#include <Python.h>
#include <filesystem>
#include "manifest.hpp"

void test1()
{
	std::string buf = "resources/test1.json";
	std::filesystem::path path(buf);
	plt_manager::manifest *json_manifest = new plt_manager::manifest(path);
	json_manifest->load_manifest();
	bool validated = json_manifest->validate_manifest();
	assert(validated == true);
}




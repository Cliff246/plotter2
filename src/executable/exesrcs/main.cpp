#include <iostream>
#include <Python.h>
#include <filesystem>
#include "manifest.hpp"

int32_t main() 
{
	std::string buf;
	std::cin >> buf;
	std::filesystem::path path(buf);
	plt_manager::manifest *json_manifest = new plt_manager::manifest(path);
	json_manifest->load_manifest();
	std::cout << json_manifest->validate_manifest();
	delete json_manifest;
	return 0;
}

cmake_minimum_required(VERSION 3.10)

find_package(nlohmann_json CONFIG REQUIRED)
add_subdirectory(shared)
add_subdirectory(datter)
add_subdirectory(manager)
add_subdirectory(grapher)
add_library(plotter2_lib STATIC "plotter.cpp") 

target_include_directories(plotter2_lib PUBLIC
	grapher_lib
	manager_lib		
	shared_lib
	datter_lib
)



target_link_libraries(plotter2_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	nlohmann_json::nlohmann_json

	PUBLIC
	datter_lib
	shared_lib
	grapher_lib
	manager_lib
)

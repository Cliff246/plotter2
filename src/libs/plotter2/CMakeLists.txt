cmake_minimum_required(VERSION 3.10)

add_subdirectory(grapher)
add_subdirectory(manager)
add_subdirectory(scripter)

add_library(plotter2_lib STATIC "plotter.cpp") 

target_include_directories(plotter2_lib PUBLIC
	grapher_lib
	manager_lib		
	scripter_lib
)

target_link_libraries(plotter2_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	PUBLIC
	grapher_lib
	manager_lib
	scripter_lib
)

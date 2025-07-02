

add_subdirectory(datatypes)
add_subdirectory(datasrc)
add_subdirectory(dataframe)
cmake_minimum_required(VERSION 3.10)
set(DATTER_CORE_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datter.cpp	
)	



add_library(datter_core_lib ${DATTER_CORE_SUBLIB_SOURCES})

target_include_directories(datter_core_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_core_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
		
	shared_lib
	pipeline_lib
	PUBLIC
	
	datter_datatypes_lib
	datter_datasrc_lib
	nlohmann_json::nlohmann_json
)

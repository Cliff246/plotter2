
cmake_minimum_required(VERSION 3.10)
set(DATTER_DATAFRAME_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataframe.cpp
)



add_library(datter_dataframe_lib ${DATTER_DATAFRAME_SUBLIB_SOURCES})

target_include_directories(datter_dataframe_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_dataframe_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
	datter_datatypes_lib	
	shared_lib
	pipeline_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)

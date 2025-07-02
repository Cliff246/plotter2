
cmake_minimum_required(VERSION 3.10)
set(DATTER_DATATYPES_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_integer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_number.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_string.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholder.cpp
)




add_library(datter_datatypes_lib ${DATTER_DATATYPES_SUBLIB_SOURCES})

target_include_directories(datter_datatypes_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_datatypes_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
	
	shared_lib
	pipeline_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)

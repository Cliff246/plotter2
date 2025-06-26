

cmake_minimum_required(VERSION 3.10)
set(DATTER_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datter.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholder.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datasrc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datasrc_csv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datasrc_json.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_integer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_number.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_string.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/dataholders/dataholder_map.cpp
)




add_library(datter_lib ${DATTER_SUBLIB_SOURCES})

target_include_directories(datter_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
	
	shared_lib
	pipeline_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)

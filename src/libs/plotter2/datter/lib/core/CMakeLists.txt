





set(DATTER_CORE_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datter.cpp	
)	




set(DATTER_DATASRC_SUBLIB_SOURCES
	
	${CMAKE_CURRENT_SOURCE_DIR}/datasrc/sources/datasrc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datasrc/sources/datasrc_csv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datasrc/sources/datasrc_json.cpp
)

set(DATTER_DATATYPES_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholders/dataholder_array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholders/dataholder_integer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholders/dataholder_number.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholders/dataholder_string.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholders/dataholder_array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/sources/dataholder.cpp
)

add_library(datter_core_lib 
	${DATTER_CORE_SUBLIB_SOURCES}
	${DATTER_DATASRC_SUBLIB_SOURCES}
	${DATTER_DATATYPES_SUBLIB_SOURCES}
)

target_include_directories(datter_core_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/datasrc/include
	${CMAKE_CURRENT_SOURCE_DIR}/datatypes/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_core_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
		
	shared_lib
	PUBLIC
	
	nlohmann_json::nlohmann_json
)


cmake_minimum_required(VERSION 3.10)

set(MANAGER_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/manager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/manifest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/file_manager.cpp
)



add_library(manager_lib ${MANAGER_SUBLIB_SOURCES})

target_include_directories(manager_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(manager_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
	
	shared_lib
	pipeline_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)

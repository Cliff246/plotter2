
cmake_minimum_required(VERSION 3.10)

set(MANAGER_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/manager.cpp
)



add_library(manager_lib ${MANAGER_SUBLIB_SOURCES})

target_include_directories(manager_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(manager_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	PUBLIC
)

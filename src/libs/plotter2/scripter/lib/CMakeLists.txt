cmake_minimum_required(VERSION 3.10)

set(SCRIPTER_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/scripter.cpp
)



add_library(scripter_lib ${SCRIPTER_SUBLIB_SOURCES})

target_include_directories(scripter_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(scripter_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	PUBLIC
)

cmake_minimum_required(VERSION 3.10)

SET(GRAPHER_SUBLIB_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/grapher.cpp
)

add_library(grapher_lib ${GRAPHER_SUBLIB_SOURCES})

target_include_directories(grapher_lib PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(grapher_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	shared_lib
	PUBLIC
)


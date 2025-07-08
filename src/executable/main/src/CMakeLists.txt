cmake_minimum_required(VERSION 3.10)

SET(MAIN_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/runtime.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/process.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/orchestration.cpp
)

add_library(p2exe ${MAIN_SOURCES})

target_link_libraries(p2exe 
	PUBLIC
	plotter2_lib
    Eigen3::Eigen
	parent_lib
	messenger_shared_lib
)

target_include_directories(p2exe PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

FILE(COPY test.json DESTINATION "${CMAKE_BINARY_DIR}")


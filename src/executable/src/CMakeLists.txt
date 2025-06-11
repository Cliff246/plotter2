cmake_minimum_required(VERSION 3.10)

SET(EXESRC 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(exe ${EXESRC})

target_link_libraries(exe 
	PRIVATE 
	plotter2_lib
    Eigen3::Eigen
    Python3::Python
)


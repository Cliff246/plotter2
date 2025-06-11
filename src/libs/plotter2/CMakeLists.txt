cmake_minimum_required(VERSION 3.10)
#TO REWRITE
set(TEMPSRC
	${CMAKE_CURRENT_SOURCE_DIR}/temp/plotter2.cpp
)

add_library(plotter2_lib ${TEMPSRC})
target_link_libraries(plotter2_lib 
	PRIVATE
    Eigen3::Eigen
    Python3::Python
)

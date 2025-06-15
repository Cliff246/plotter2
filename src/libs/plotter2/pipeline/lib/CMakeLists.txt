
cmake_minimum_required(VERSION 3.10)

set(PIPELINE_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/pipeline.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/layer.cpp
)



add_library(pipeline_lib ${PIPELINE_SUBLIB_SOURCES})

target_include_directories(pipeline_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(pipeline_lib
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	shared_lib
	PUBLIC
)

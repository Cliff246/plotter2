cmake_minimum_required(VERSION 3.10)

SET(CHILD_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/worker.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/listener.cpp

)

add_executable(child ${CHILD_SOURCES})

find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(child 
	PRIVATE 
	plotter2_lib
    Eigen3::Eigen
    Python3::Python	
	child_lib
	nlohmann_json::nlohmann_json
)

target_include_directories(child PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(child PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

cmake_minimum_required(VERSION 3.10)

SET(MAIN_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/runtime.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/process.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/orchestration.cpp
)

add_executable(exe ${MAIN_SOURCES})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(exe 
	PRIVATE 
	plotter2_lib
    Eigen3::Eigen
    Python3::Python
	parent_lib
	messenger_shared_lib
	nlohmann_json::nlohmann_json
)

target_include_directories(exe PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

FILE(COPY test.json DESTINATION "${CMAKE_BINARY_DIR}")

set_target_properties(exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

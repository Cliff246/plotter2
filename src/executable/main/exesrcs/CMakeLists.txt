cmake_minimum_required(VERSION 3.10)

SET(EXESRC 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(exe ${EXESRC})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(exe 
	PRIVATE 
	plotter2_lib
    Eigen3::Eigen
    Python3::Python
	

	nlohmann_json::nlohmann_json
)

FILE(COPY test.json DESTINATION "${CMAKE_BINARY_DIR}")
set_target_properties(exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

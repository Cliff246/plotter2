cmake_minimum_required(VERSION 3.10)


set(EXE_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/exe.cpp
)

add_executable(exe ${EXE_SOURCES})


target_link_libraries(exe
	p2exe
)

target_include_directories(exe PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
	

cmake_minimum_required(VERSION 3.10)
enable_testing()

set(P2MAIN_SOURCES_TESTS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/start_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/runtime_tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/testscommons.cpp
)
add_executable(p2main_tests ${P2MAIN_SOURCES_TESTS})
target_include_directories(p2main_tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	

gtest_discover_tests(p2main_tests)
target_link_libraries(p2main_tests

	PRIVATE
	Eigen3::Eigen
    Python3::Python
	gtest_main	
	p2exe
)
add_test(NAME p2main_tests COMMAND p2main_tests)
# Copy the resources directory to the build dir
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
 



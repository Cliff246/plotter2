
set(UTILS_SOURCES_TEST 
	${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/fhold_tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/process_inspector_tests.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/tests/utils_cpp_tests.cpp
)



enable_testing()


add_executable(utils_tests ${UTILS_SOURCES_TEST})
target_include_directories(utils_tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	

gtest_discover_tests(utils_tests)

target_link_libraries(utils_tests
	PRIVATE
	Eigen3::Eigen
    Python3::Python
	shared_lib
	gtest_main	
	PUBLIC
	nlohmann_json::nlohmann_json
)
add_test(NAME utils_tests COMMAND utils_tests)
# Copy the resources directory to the build dir
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
 )

 


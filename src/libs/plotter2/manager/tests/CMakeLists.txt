enable_testing()

set(MANAGER_SOURCES_TESTS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests_manifest.cpp
	
	
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests.cpp
)
add_executable(manager_tests ${MANAGER_SOURCES_TESTS})
target_include_directories(manager_tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	
target_link_libraries(manager_tests

	PRIVATE
	Eigen3::Eigen
    Python3::Python
	
	shared_lib
	pipeline_lib
	manager_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)
add_test(NAME manager_tests COMMAND manager_tests)
# Copy the resources directory to the build dir
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

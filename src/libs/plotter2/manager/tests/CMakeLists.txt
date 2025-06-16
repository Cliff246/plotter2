enable_testing()

set(MANAGER_SOURCES_TESTS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests_manifest.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests_manager.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests.cpp
)
add_executable(manager_tests ${MANAGER_SOURCES_TESTS})
target_include_directories(manager_tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
gtest_discover_tests(manager_tests)
target_link_libraries(manager_tests

	PRIVATE
	Eigen3::Eigen
    Python3::Python
	gtest_main	
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

 


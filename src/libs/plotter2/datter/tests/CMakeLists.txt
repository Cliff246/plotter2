
set(DATTER_SOURCES_TEST 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datter_tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/datasrc_csv_tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/tests.cpp
)



enable_testing()


add_executable(datter_tests ${DATTER_SOURCES_TEST})
target_include_directories(datter_tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	

gtest_discover_tests(datter_tests)

target_link_libraries(datter_tests
	PRIVATE
	datter_lib
	Eigen3::Eigen
    Python3::Python
	shared_lib
	gtest_main	
	PUBLIC
	nlohmann_json::nlohmann_json
)
add_test(NAME datter_tests COMMAND datter_tests)
# Copy the resources directory to the build dir
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

 




add_subdirectory(core)
add_subdirectory(models)
add_subdirectory(taskimpl)



set(DATTER_SUBLIB_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/base_datter.cpp
)


add_library(datter_lib ${DATTER_SUBLIB_SOURCES})

target_include_directories(datter_lib PUBLIC 	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
		
	shared_lib
	pipeline_lib
	PUBLIC
	datter_core_lib
	datter_model_lib
	pipeline_lib

	nlohmann_json::nlohmann_json
)

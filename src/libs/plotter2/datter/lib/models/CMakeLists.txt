

set(DATTER_FRAME_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/frames/sources/frame.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/frames/sources/item.cpp

)

set(DATTER_BUNDLE_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/sources/bundle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/sources/bundle_shared.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/sources/bundle_container.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/sources/bundle_element.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/sources/bundle_node.cpp
)

set(DATTER_TASK_SUBLIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/tasks/sources/task.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tasks/sources/task_context.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tasks/sources/active_task.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tasks/sources/tasker.cpp
)
#this won't work lol
if(CHILD)
	add_compile_definitions(CHILD=1)
else()	
	add_compile_definitions(CHILD=0)
endif()


add_library(datter_model_lib
	${DATTER_BUNDLE_SUBLIB_SOURCES}
	${DATTER_FRAME_SUBLIB_SOURCES}
	${DATTER_TASK_SUBLIB_SOURCES}
)


target_include_directories(datter_model_lib PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/frames/include
	${CMAKE_CURRENT_SOURCE_DIR}/bundles/include
	${CMAKE_CURRENT_SOURCE_DIR}/tasks/include
)


find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(datter_model_lib 
	PRIVATE 
    Eigen3::Eigen
    Python3::Python
	datter_core_lib		
	shared_lib
	PUBLIC
	
	nlohmann_json::nlohmann_json
)



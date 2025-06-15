
set(PLOTS_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plot.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plotobject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plotscene.cpp

)
set(SCRIPTER_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/scripter/sources/scripter.cpp
)
set(DATTER_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/datter/sources/datter.cpp
)

set(UTILS_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/fileholder.cpp
)

add_library(shared_lib STATIC 
	${PLOTS_SOURCES}
	${SCRIPTER_SOURCES}
	${DATTER_SOURCES}
	${UTILS_SOURCES}
)

target_include_directories(shared_lib 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/plots/include
	${CMAKE_CURRENT_SOURCE_DIR}/scripter/include
	${CMAKE_CURRENT_SOURCE_DIR}/datter/include
	${CMAKE_CURRENT_SOURCE_DIR}/utils/include
)
target_link_libraries(shared_lib
	PRIVATE
    Eigen3::Eigen
    Python3::Python
)

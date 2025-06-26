
set(PLOTS_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plot.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plotobject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/plots/sources/plotscene.cpp

)
set(SCRIPTER_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/scripter/sources/scripter.cpp
)

set(LOGGY_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/loggy/sources/loggy.cpp
)


set(UTILS_SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/fhold.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/utils_threadpool.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/utils_threadworker.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/dependency.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/fholdtypes/file_holder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/utils/sources/fholdtypes/directory_holder.cpp
)


add_library(shared_lib STATIC 
	${LOGGY_SOURCES}
	${PLOTS_SOURCES}
	${SCRIPTER_SOURCES}
	${UTILS_SOURCES}
)


target_include_directories(shared_lib 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/plots/include
	${CMAKE_CURRENT_SOURCE_DIR}/scripter/include
	${CMAKE_CURRENT_SOURCE_DIR}/utils/include
	${CMAKE_CURRENT_SOURCE_DIR}/loggy/include
)

target_link_libraries(shared_lib
	PRIVATE
    Eigen3::Eigen
    Python3::Python
	nlohmann_json 
)

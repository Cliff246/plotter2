set(CHILDREN_SOURCES_LIBRARY
	${CMAKE_CURRENT_SOURCE_DIR}/sources/child.cpp
)


add_library(child_lib STATIC ${CHILDREN_SOURCES_LIBRARY}) 

target_include_directories(child_lib PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)



target_link_libraries(child_lib
	messenger_shared_lib
)

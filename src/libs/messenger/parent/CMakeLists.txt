set(PARENT_SOURCES_LIBRARY
	${CMAKE_CURRENT_SOURCE_DIR}/sources/parent.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/childholder.cpp
)


add_library(parent_lib STATIC ${PARENT_SOURCES_LIBRARY}) 

target_include_directories(parent_lib 
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(parent_lib 
	messenger_shared_lib	
)	


set(MESSENGER_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/sources/message.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/socketer.cpp
)

set(MESSENGER_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/include/message.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/socketer.hpp
)

add_library(messenger_shared_lib STATIC ${MESSENGER_SOURCES} ${MESSENGER_HEADERS})

target_include_directories(messenger_shared_lib
   	PUBLIC	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)	




set(This gameLogic)

set(headers
	gameLogic.hpp
	utils.hpp
)

set(sources
	update.cpp
	render.cpp
	utils.cpp
)

add_library(${This} SHARED ${headers} ${sources})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${This} PRIVATE classes)
set(This classes)

set(headers
	card.hpp
	cardPile.hpp
	deck.hpp
	drawPile.hpp
	column.hpp
	foundation.hpp
	direction.hpp
	linkable.hpp
	section.hpp
	cursor.hpp
	game.hpp
)

set(sources
	card.cpp
	cardPile.cpp
	deck.cpp
	drawPile.cpp
	column.cpp
	foundation.cpp
	direction.cpp
	linkable.cpp
	section.cpp
	cursor.cpp
	game.cpp
)

add_library(${This} SHARED ${headers} ${sources})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

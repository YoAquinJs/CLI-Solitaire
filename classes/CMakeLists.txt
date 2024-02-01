set(This classes)

set(headers
	card.hpp
	deck.hpp
	piles.hpp
	linkable.hpp
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
	section.cpp
	cursor.cpp
	game.cpp
)

add_library(${This} SHARED ${headers} ${sources})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

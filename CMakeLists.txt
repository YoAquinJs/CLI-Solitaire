cmake_minimum_required(VERSION 3.28)

set(This Solitarie)
project(${This})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(classes)
add_subdirectory(gameLogic)

add_executable(${This} main.cpp)

target_link_libraries(${This}
	classes
	gameLogic
)

cmake_minimum_required(VERSION 3.0)

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

# Optionally, if you have header files in a separate directory, you can include them like this:
# include_directories(include)

# Optionally, if you have external libraries, you can find and link them like this:
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(MyExecutable SomeLibrary::SomeLibrary)

cmake_minimum_required(VERSION 3.16)
project(2DEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)

FetchContent_MakeAvailable(sfml)

add_executable(2DEngine
    src/main.cpp
    src/Core/Types.hpp
)

target_include_directories(2DEngine PRIVATE include)

target_link_libraries(2DEngine
    sfml-graphics
    sfml-window
    sfml-system
)
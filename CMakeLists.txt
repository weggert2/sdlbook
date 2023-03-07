cmake_minimum_required (VERSION 3.8)

project(sdlbook)
set (CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

# Shortcut - get all of the sources. You probably don't want
# to do this in production.
file(
    GLOB all_srcs
    src/main.cpp
)

# Build the game. Hope you enjoy!
if (MSVC)
    add_executable(${PROJECT_NAME} WIN32 ${all_srcs} )
else()
    add_executable(${PROJECT_NAME} ${all_srcs} )
endif()

# Turn on compile warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Wextra
        -Werror
        -Wdouble-promotion
        -Wshadow
        -Wformat=2
        -Wno-narrowing
        -fPIC
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /W3
        /WX
    >
)

target_link_libraries(${PROJECT_NAME} SDL2)

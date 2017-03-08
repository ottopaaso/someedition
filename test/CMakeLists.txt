cmake_minimum_required(VERSION 2.8.11)

project(SomeEditionTests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SOURCES
    FilterableImageTest.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

find_package(Qt5Test REQUIRED)
add_executable(SomeEditionTests testmain.cpp ${SOURCES})

target_link_libraries(SomeEditionTests ImageFilterLib Qt5::Test)

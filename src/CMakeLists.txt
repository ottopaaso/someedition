cmake_minimum_required(VERSION 2.8.11)

project(ImageFilterLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(HEADERS
    FilterableImage.h
)

set(SOURCES
    FilterableImage.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Qt5 COMPONENTS Quick)
add_library(ImageFilterLib SHARED ${SOURCES})
qt5_use_modules(ImageFilterLib Quick)
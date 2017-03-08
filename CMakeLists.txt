cmake_minimum_required(VERSION 2.8.11)

project(SomeEdition)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(Qt5 COMPONENTS Quick Core)
qt5_add_resources(RESOURCES qml.qrc)
add_executable(SomeEdition MACOSX_BUNDLE main.cpp ${RESOURCES})
target_link_libraries(SomeEdition ImageFilterLib)
qt5_use_modules(SomeEdition Quick Core)

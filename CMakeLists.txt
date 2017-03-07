cmake_minimum_required(VERSION 2.8.11)

project(SomeEdition)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Quick Core)
qt5_add_resources(RESOURCES qml.qrc)
add_executable(SomeEdition MACOSX_BUNDLE main.cpp ${RESOURCES})
qt5_use_modules(SomeEdition Quick Core)

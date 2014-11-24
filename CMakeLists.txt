cmake_minimum_required(VERSION 2.8.11)
project(EdisenseClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to run uic automatically when needed.
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

include_directories(src/ui src/controller src/model)

set(SOURCE_FILES main.cpp
                 src/ui/ui_Edisense.h
                 src/ui/HomeView.h
                 src/ui/HomeView.cpp
                 src/ui/NodeViewModel.h
                 src/ui/NodeViewModel.cpp
                 src/controller/HomeController.h
                 src/controller/HomeController.cpp
                 src/model/Configuration.h
                 src/model/Node.h
                 src/model/NodeManager.h)

add_executable(EdisenseClient ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(EdisenseClient Qt5::Widgets)
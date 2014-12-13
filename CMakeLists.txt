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
find_package(Qt5Widgets REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_subdirectory(ext/Comms)

include_directories(src/ui src/controller src/model)
include_directories(ext/Comms/include)

set(SOURCE_FILES main.cpp
                 src/model/Configuration.h
                 src/model/Node.h
                 src/model/NodeManager.h
                 src/model/PollerDaemon.h
                 src/model/PollerDaemon.cpp
                 )

add_executable(EdisenseClient ${SOURCE_FILES})
target_link_libraries(EdisenseClient zmqpp)
target_link_libraries(EdisenseClient EdisenseComms)

# Use the Widgets module from Qt 5.
target_link_libraries(EdisenseClient Qt5::Widgets)
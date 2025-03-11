cmake_minimum_required(VERSION 3.28)
project(Lab02)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS} include)
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

# Disable all warnings
add_compile_options(-w)

# Collect all source files in core/ directory
file(GLOB CORE_SOURCES core/*.cpp)

# Create object files for core sources
add_library(CORE_OBJECT OBJECT ${CORE_SOURCES})

# Set and create first executable
set(EXECUTABLE_LAB02 "Lab02")
message(STATUS "Creating executable: ${EXECUTABLE_LAB02}")
add_executable(${EXECUTABLE_LAB02} main.cpp)
target_link_libraries(${EXECUTABLE_LAB02} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# Set and create second executable
set(EXECUTABLE_HELLO_WORLD "hello_world")
message(STATUS "Creating executable: ${EXECUTABLE_HELLO_WORLD}")
add_executable(${EXECUTABLE_HELLO_WORLD} tests/hello_world.cpp)
target_link_libraries(${EXECUTABLE_HELLO_WORLD} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# Set and create third executable 
set(EXECUTABLE_WINDOW "window")
message(STATUS "Creating executable: ${EXECUTABLE_WINDOW}")
add_executable(${EXECUTABLE_WINDOW} tests/window.cpp) 
target_link_libraries(${EXECUTABLE_WINDOW} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(${EXECUTABLE_WINDOW} CORE_OBJECT)

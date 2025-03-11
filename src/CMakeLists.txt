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

# Compile all source files in drawable/ directory
file(GLOB DRAWABLE_SOURCES drawable/*.cpp)

# Create object files for drawable sources 
add_library(DRAWABLE_OBJECT OBJECT ${DRAWABLE_SOURCES})

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
target_link_libraries(${EXECUTABLE_WINDOW} CORE_OBJECT DRAWABLE_OBJECT)

# Set and create fourth executable 
set(EXECUTABLE_LINE "line") 
message(STATUS "Creating executable: ${EXECUTABLE_LINE}") 
add_executable(${EXECUTABLE_LINE} tests/line.cpp) 
target_link_libraries(${EXECUTABLE_LINE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_LINE} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create fifth executable 
set(EXECUTABLE_EQUIL_TRIANGLE "equil_triangle")
message(STATUS "Creating executable: ${EXECUTABLE_EQUIL_TRIANGLE}") 
add_executable(${EXECUTABLE_EQUIL_TRIANGLE} tests/equil_triangle.cpp) 
target_link_libraries(${EXECUTABLE_EQUIL_TRIANGLE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_EQUIL_TRIANGLE} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create sixth executable 
set(EXECUTABLE_RIGHT_ISOSCELES_TRIANGLE "right_isosceles_triangle")
message(STATUS "Creating executable: ${EXECUTABLE_RIGHT_ISOSCELES_TRIANGLE}") 
add_executable(${EXECUTABLE_RIGHT_ISOSCELES_TRIANGLE} tests/right_isosceles_triangle.cpp) 
target_link_libraries(${EXECUTABLE_RIGHT_ISOSCELES_TRIANGLE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_RIGHT_ISOSCELES_TRIANGLE} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create seventh executable 
set(EXECUTABLE_RECTANGLE "rectangle") 
message(STATUS "Creating executable: ${EXECUTABLE_RECTANGLE}") 
add_executable(${EXECUTABLE_RECTANGLE} tests/rectangle.cpp) 
target_link_libraries(${EXECUTABLE_RECTANGLE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_RECTANGLE} CORE_OBJECT DRAWABLE_OBJECT)

# Set and create eighth executable 
set(EXECUTABLE_SQUARE "square")
message(STATUS "Creating executable: ${EXECUTABLE_SQUARE}")
add_executable(${EXECUTABLE_SQUARE} tests/square.cpp)
target_link_libraries(${EXECUTABLE_SQUARE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(${EXECUTABLE_SQUARE} CORE_OBJECT DRAWABLE_OBJECT)

# Set and create ninth executable 
set(EXECUTABLE_PENTAGON "pentagon") 
message(STATUS "Creating executable: ${EXECUTABLE_PENTAGON}") 
add_executable(${EXECUTABLE_PENTAGON} tests/pentagon.cpp) 
target_link_libraries(${EXECUTABLE_PENTAGON} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_PENTAGON} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create tenth executable 
set(EXECUTABLE_HEXAGON "hexagon") 
message(STATUS "Creating executable: ${EXECUTABLE_HEXAGON}") 
add_executable(${EXECUTABLE_HEXAGON} tests/hexagon.cpp) 
target_link_libraries(${EXECUTABLE_HEXAGON} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_HEXAGON} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create eleventh executable 
# addition 
set(EXECUTABLE_ADDITION "addition") 
message(STATUS "Creating executable: ${EXECUTABLE_ADDITION}") 
add_executable(${EXECUTABLE_ADDITION} tests/addition.cpp) 
target_link_libraries(${EXECUTABLE_ADDITION} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_ADDITION} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create twelfth executable 
# subtraction 
set(EXECUTABLE_SUBTRACTION "subtraction") 
message(STATUS "Creating executable: ${EXECUTABLE_SUBTRACTION}") 
add_executable(${EXECUTABLE_SUBTRACTION} tests/subtraction.cpp) 
target_link_libraries(${EXECUTABLE_SUBTRACTION} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_SUBTRACTION} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create thirteenth executable 
# multiplication 
set(EXECUTABLE_MULTIPLICATION "multiplication") 
message(STATUS "Creating executable: ${EXECUTABLE_MULTIPLICATION}") 
add_executable(${EXECUTABLE_MULTIPLICATION} tests/multiplication.cpp) 
target_link_libraries(${EXECUTABLE_MULTIPLICATION} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_MULTIPLICATION} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create fourteenth executable 
# division
set(EXECUTABLE_DIVISION "division") 
message(STATUS "Creating executable: ${EXECUTABLE_DIVISION}") 
add_executable(${EXECUTABLE_DIVISION} tests/division.cpp) 
target_link_libraries(${EXECUTABLE_DIVISION} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_DIVISION} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create fifteenth executable 
# arrow 
set(EXECUTABLE_ARROW "arrow") 
message(STATUS "Creating executable: ${EXECUTABLE_ARROW}") 
add_executable(${EXECUTABLE_ARROW} tests/arrow.cpp) 
target_link_libraries(${EXECUTABLE_ARROW} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_ARROW} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create sixteenth executable 
# star 
set(EXECUTABLE_STAR "star") 
message(STATUS "Creating executable: ${EXECUTABLE_STAR}") 
add_executable(${EXECUTABLE_STAR} tests/star.cpp)
target_link_libraries(${EXECUTABLE_STAR} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_STAR} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create seventeenth executable 
# circle 
set(EXECUTABLE_CIRCLE "circle") 
message(STATUS "Creating executable: ${EXECUTABLE_CIRCLE}") 
add_executable(${EXECUTABLE_CIRCLE} tests/circle.cpp) 
target_link_libraries(${EXECUTABLE_CIRCLE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_CIRCLE} CORE_OBJECT DRAWABLE_OBJECT) 

# Set and create eighteenth executable 
# ellipse 
set(EXECUTABLE_ELLIPSE "ellipse") 
message(STATUS "Creating executable: ${EXECUTABLE_ELLIPSE}") 
add_executable(${EXECUTABLE_ELLIPSE} tests/ellipse.cpp)
target_link_libraries(${EXECUTABLE_ELLIPSE} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}) 
target_link_libraries(${EXECUTABLE_ELLIPSE} CORE_OBJECT DRAWABLE_OBJECT) 


cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "test_shapes")
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

add_subdirectory(src)
add_subdirectory(glut/FreeGLUT/freeglut/freeglut)
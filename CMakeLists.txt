cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Prototype)


file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)

find_package(OpenGL REQUIRED)

add_executable(game ${SRC_FILES})

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(game PUBLIC ${GLFW_INCLUDE_DIR})
target_link_libraries(game PUBLIC GL GLU glut GLEW glfw X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor)
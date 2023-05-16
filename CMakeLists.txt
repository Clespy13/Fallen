cmake_minimum_required(VERSION 3.10)

project(Fallen VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

# Avoid building the tests, examples and docs
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(SOURCES
    src/main.cpp
    src/Logger.cpp
)

add_executable(Fallen ${SOURCES})

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

target_link_libraries(Fallen PRIVATE ${OPENGL_LIBRARIES} glfw glad)

#target_include_directories(Fallen PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                          "${PROJECT_SOURCE_DIR}/glad"
#                          )

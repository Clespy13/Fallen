cmake_minimum_required(VERSION 3.10)

project(Fallen VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

# STATIC stuff (Windows)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(BUILD_FOR_WIN TRUE)
endif()
option(STATIC_BUILD "Build a static binary." ${BUILD_FOR_WIN})

if (STATIC_BUILD)
        set(CMAKE_EXE_LINKER_FLAGS "-static")
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
        set(BUILD_SHARED_LIBS OFF)
endif()

# Avoid building the tests, examples and docs
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(SOURCES
    src/main.cpp
    src/Logger.cpp
    src/Window.cpp
    src/Application.cpp
    src/LayerStack.cpp
)

add_executable(Fallen ${SOURCES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Fallen)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

target_link_libraries(Fallen PRIVATE ${OPENGL_LIBRARIES} glfw glad)

#target_include_directories(Fallen PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                          "${PROJECT_SOURCE_DIR}/glad"
#                          )

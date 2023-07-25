cmake_minimum_required(VERSION 3.10)

project(FallenLib VERSION 0.1.0)


#find_package(OpenGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIRS})

#add_subdirectory(libs/glm)
add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

set(glm_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/glm/cmake/glm")
find_package(glm REQUIRED)

file(GLOB_RECURSE HEADERS "src/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Run macro
GroupSources(src)

add_library(FallenLib SHARED ${SOURCES} ${HEADERS})

# Avoid building the tests, examples and docs
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_include_directories(FallenLib PUBLIC "src" ${GLM_INCLUDE_DIRS})
#include_directories(${GLM_INCLUDE_DIRS})

#${OPENGL_LIBRARIES}
target_link_libraries(FallenLib PRIVATE ${GLM_LIBRARY_DIRS} glfw glad glm::glm)

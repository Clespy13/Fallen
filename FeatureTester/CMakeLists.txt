cmake_minimum_required(VERSION 3.10)

project(FeatureTester VERSION 0.1.0)

file(GLOB_RECURSE HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(FeatureTester ${SOURCES} ${HEADERS})

# Run macro
GroupSources(src)

target_link_libraries(FeatureTester FallenLib)

target_include_directories(FeatureTester PUBLIC .)
cmake_minimum_required(VERSION 3.10)

project(Fallen VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

set(OSBitness 32)
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()


#set(CMAKE_MODULE_PATH "${Fallen_SOURCE_DIR}/cmake")

set(FullOutputDir "${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_SYSTEM_NAME}${OSBitness}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # to force generation of .lib as well
else()
	add_compile_options(-fPIC)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Macro to preserve source files hierarchy in the IDE
macro(GroupSources curdir)
	file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

	foreach(child ${children})
		if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
			GroupSources(${curdir}/${child})
		else()
			string(REPLACE "/" "\\" groupname ${curdir})
			string(REPLACE "src" "Sources" groupname ${groupname})
			source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
		endif()
	endforeach()
endmacro()

add_subdirectory(Fallen)
add_subdirectory(FeatureTester)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FeatureTester)

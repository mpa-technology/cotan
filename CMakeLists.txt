cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project (COTAN)

set(COTAN_LIBRARY_NAME "cotan")
set(COTAN_VERSION_MAJOR 1)
set(COTAN_VERSION_MINOR 0)
set(COTAN_VERSION_PATCH 1)
set(PROJECT_VERSION ${COTAN_VERSION_MAJOR}.${COTAN_VERSION_MINOR}.${COTAN_VERSION_PATCH})




option(BUILD_TESTS  "Enable to build test for cotan library" ON)
option(BUILD_STATIC "Build static library" ON)








include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE COTAN_LIBRARY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


if(BUILD_STATIC)
    add_library( ${COTAN_LIBRARY_NAME} STATIC ${COTAN_LIBRARY_SOURCES})
else()
    add_library( ${COTAN_LIBRARY_NAME} SHARED ${COTAN_LIBRARY_SOURCES})
endif()


if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()








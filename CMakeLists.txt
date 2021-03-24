cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project (COTAN)

set(COTAN_LIBRARY_NAME "cotan")
set(COTAN_VERSION_MAJOR 0)
set(COTAN_VERSION_MINOR 0)
set(COTAN_VERSION_PATCH 1)
set(PROJECT_VERSION ${COAN_VERSION_MAJOR}.${COTAN_VERSION_MINOR}.${COTAN_VERSION_PATCH})

SET(CMAKE_CXX_FLAGS "-march=native")


option(BUILD_STATIC "Build static library" ON)
option(BUILD_TESTS  "Enable to build test for cotan library" ON)
option(USE_SPECIFICALLY_PLATFORM "Use platform api" ON)



file(GLOB_RECURSE COTAN_LIBRARY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/random/*.cpp)

if(USE_SPECIFICALLY_PLATFORM)
    add_definitions( -DUSE_SPECIFICALLY_PLATFORM=1)
    set(CMAKE_CXX_FLAGS "-march=native")
    file(GLOB_RECURSE COTAN_LIBRARY_NATIVE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/native/*.cpp)
endif()



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)




if(BUILD_STATIC)
    add_library( ${COTAN_LIBRARY_NAME} STATIC ${COTAN_LIBRARY_SOURCES} ${COTAN_LIBRARY_NATIVE_SOURCES})
else()
    add_library( ${COTAN_LIBRARY_NAME} SHARED ${COTAN_LIBRARY_SOURCES} ${COTAN_LIBRARY_NATIVE_SOURCES})
endif()


if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()








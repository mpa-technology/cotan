cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project (COTAN)

set(COTAN_LIBRARY_NAME "cotan")
set(COTAN_VERSION_MAJOR 1)
set(COTAN_VERSION_MINOR 0)
set(COTAN_VERSION_PATCH 0)
set(PROJECT_VERSION ${COTAN_VERSION_MAJOR}.${COTAN_VERSION_MINOR}.${COTAN_VERSION_PATCH})




set(BUILD_TESTS   BOOL "Enable to build test for cotan" ON)
set(INSTALL_HEADERS   BOOL "Enable to install header files" ON)
set(BUILD_DEB   BOOL "Create deb package" ON)
set(INSTALL_LIBRARY_DESTINATION "/usr/lib/x86_64-linux-gnu/")
set(USE_SPECIFICALLY_PLATFORM ON)


if(USE_SPECIFICALLY_PLATFORM)
    set(COTON_BUILD_NATIVE 1)
    set(CMAKE_CXX_FLAGS "-march=native")
    else()
        set(COTON_BUILD_NATIVE 0)
endif()





include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

configure_file(${PROJECT_SOURCE_DIR}/include/cotan/cotan/buildFlag.in ${PROJECT_SOURCE_DIR}/include/cotan/cotan/buildFlag.hpp)



file(GLOB_RECURSE COTAN_LIBRARY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)



add_library( ${COTAN_LIBRARY_NAME} SHARED ${COTAN_LIBRARY_SOURCES})


if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()


if(INSTALL_HEADERS)
    install(
            DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
            DESTINATION .
            FILES_MATCHING PATTERN "*.hpp"
           )
    install(
            DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include
            DESTINATION .
            FILES_MATCHING PATTERN "*.hpp"
           )
endif()

set_target_properties(${COTAN_LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${COTAN_VERSION_MAJOR}
    )


install(
    TARGETS ${COTAN_LIBRARY_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION ${INSTALL_LIBRARY_DESTINATION}
    ARCHIVE DESTINATION lib
    )


iF(BUILD_DEB)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "mpa-technology")
set(CPACK_PACKAGE_NAME ${COTAN_LIBRARY_NAME})
set(CPACK_PACKAGE_VENDOR "mpa-technology")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cryptography tools lib" )
set(CPACK_PACKAGE_DESCRIPTION "Cryptography tools lib" )

set(CPACK_PACKAGE_VERSION_MAJOR ${COTAN_VERSION_MAJOR} )
set(CPACK_PACKAGE_VERSION_MINOR ${COTAN_VERSION_MINOR} )
set(CPACK_PACKAGE_VERSION_PATCH ${COTAN_VERSION_PATCH} )



INCLUDE(CPack)

endif()





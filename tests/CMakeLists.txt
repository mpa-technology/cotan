project(cotan-test)


set(COTAN_TESTING_LIBRARY_NAME "cotan_test")

option(USE_SPECIFICALLY_PLATFORM ON)
if(USE_SPECIFICALLY_PLATFORM)
    set(CMAKE_CXX_FLAGS "-march=native")
endif()



find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include(GoogleTest)
add_executable( ${PROJECT_NAME} "main.cpp")


target_link_libraries( ${PROJECT_NAME} ${GTEST_LIBRARIES} Threads::Threads cotan)



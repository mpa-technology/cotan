project(cotan-test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(COTAN_TESTING_LIBRARY_NAME "cotan_test")

option(USE_SPECIFICALLY_PLATFORM ON)
if(USE_SPECIFICALLY_PLATFORM)
    set(CMAKE_CXX_FLAGS "-march=native")
endif()





add_executable( ${PROJECT_NAME} "main.cpp" "adler32Test.hpp" "UtilityTest.hpp")


target_link_libraries( ${PROJECT_NAME} -lgtest cotan)



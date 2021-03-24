project(cotan-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(COTAN_TESTING_LIBRARY_NAME "cotan_test")







add_executable( ${PROJECT_NAME} "main.cpp" )


target_link_libraries( ${PROJECT_NAME} pthread gtest cotan)



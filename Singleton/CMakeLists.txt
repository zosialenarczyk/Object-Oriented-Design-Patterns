cmake_minimum_required(VERSION 3.21)
project(Singleton)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
)

set(SOURCE_FILES
    src
)

add_executable(Singleton_debug ${SOURCE_FILES} main.cpp)

# == Unit testing using Google Testing Framework ==

set(SOURCES_FILES_TESTS
        test)

add_executable(my_project_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

target_include_directories(my_project_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks
        )

add_subdirectory(googletest-master)

target_link_libraries(my_project_test gmock)
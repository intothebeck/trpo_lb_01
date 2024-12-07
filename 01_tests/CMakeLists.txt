cmake_minimum_required(VERSION 3.10)
project(test-example)

find_package(GTest REQUIRED)

add_executable(00_add 00_add.c)

add_executable(01_simple_print 01_simple_print.c)

add_executable(02_simple_marco 02_simple_marco.c)
if(ENABLE_GCOV)
    target_compile_options(02_simple_marco PRIVATE "--coverage")
    target_link_options(02_simple_marco PRIVATE "--coverage")
endif()

add_executable(03_gtest_simple 03_gtest_simple.cpp)
target_link_libraries(03_gtest_simple GTest::GTest)

add_executable(04_gtest_fixtures 04_gtest_fixtures.cpp)
target_link_libraries(04_gtest_fixtures GTest::GTest)

add_executable(05_gmock 05_gmock.cpp)
target_link_libraries(05_gmock GTest::gtest GTest::gmock)

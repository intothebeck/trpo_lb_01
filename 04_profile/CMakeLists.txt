cmake_minimum_required(VERSION 3.10)
project(benchmark-example)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(BENCHMARK_ENABLE_TESTING OFF)
set(ENABLE_GPROF OFF)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG main)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark
        GIT_TAG main)

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

add_executable(01_benchmark 01_benchmark.cpp)
target_link_libraries(01_benchmark benchmark::benchmark)

if(ENABLE_GPROF)
        target_compile_options(01_benchmark PRIVATE "-pg")
        target_link_options(01_benchmark PRIVATE "-pg")
endif()

add_executable(02_benchmark_fixture 02_benchmark_fixture.cpp)
target_link_libraries(02_benchmark_fixture benchmark::benchmark)

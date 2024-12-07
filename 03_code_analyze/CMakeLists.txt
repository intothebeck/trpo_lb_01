cmake_minimum_required(VERSION 3.10)
project(analyze-example)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

# Add ASAN, UBSAN, TSAN flags
if(ENABLE_ASAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

if(ENABLE_UBSAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
endif()

if(ENABLE_TSAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread")
endif()

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer")

if(ENABLE_ERRORS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
endif()

add_executable(01_oob 01_oob.c)
add_executable(02_nullptr_typo 02_nullptr_typo.c)
add_executable(03_uninit_var 03_uninit_var.c)
add_executable(04_zero_div 04_zero_div.c)
add_executable(05_switch 05_switch.c)
add_executable(06_oos 06_oos.c)
add_executable(07_leak 07_leak.c)
add_executable(08_uint_underflow 08_uint_underflow.c)
add_executable(09_invalid_cond 09_invalid_cond.c)
add_executable(10_while_typo 10_while_typo.c)
add_executable(11_invalid_logical_cond 11_invalid_logical_cond.c)
add_executable(12_string_literal 12_string_literal.c)
add_executable(13_race_condition 13_race_condition.cpp)
target_link_libraries(13_race_condition Threads::Threads)

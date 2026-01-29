cmake_minimum_required(VERSION 3.16)
project(messenger)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -fsanitize=address,undefined")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(core)
add_subdirectory(crypto)
add_subdirectory(protocol)
add_subdirectory(shared)
add_subdirectory(tests)

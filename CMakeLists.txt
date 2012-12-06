cmake_minimum_required (VERSION 2.6)

# Common packages required
project(hevcIT)

include_directories(include)

file (GLOB src_files src/*.c)

add_executable(hevcIT ${src_files})

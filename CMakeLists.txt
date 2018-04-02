cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)

project(CppUTestExamples VERSION 1.0.0)

enable_language(C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

enable_testing()
find_package(CppUTest 3.8 REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)

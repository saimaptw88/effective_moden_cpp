cmake_minimum_required(VERSION 3.10)
project(EFFECTIVE_MODEN_CPP)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(chapter3)
add_subdirectory(chapter5)
add_subdirectory(chapter6)
add_subdirectory(chapter7)

add_executable(main main.cc)
target_link_libraries(
main
PUBLIC "-pthread"
chapter3
chapter5
chapter6
chapter7
)

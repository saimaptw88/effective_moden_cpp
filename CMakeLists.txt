cmake_minimum_required(VERSION 3.10)
project(EFFECTIVE_MODEN_CPP)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs)

add_executable(exec main.cc)
target_link_libraries(
exec
PUBLIC "-pthread"
lib
)

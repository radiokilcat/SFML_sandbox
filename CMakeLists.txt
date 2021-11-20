cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(heygame)

find_package(SFML 2.5
  COMPONENTS
    system window graphics network audio REQUIRED)

add_subdirectory(libs)
add_subdirectory(examples)

cmake_minimum_required(VERSION 3.10)

project(BooksOrder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BooksOrder src/main.cpp)

target_include_directories(BooksOrder PRIVATE inc)
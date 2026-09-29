cmake_minimum_required(VERSION 3.20)

project(signal_processor
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(signal_processor
    src/main.cpp
)

target_include_directories(signal_processor
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (out)

file(GLOB SRC_SOURCES src/*.cpp src/*/*.cpp)
set(SOURCES ${SRC_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(../.. libs/taco)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include)

target_link_libraries(${PROJECT_NAME} taco)

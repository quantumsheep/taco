cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

project(taco
    VERSION "1.0.1"
    DESCRIPTION "Terminal Absolute Control and Owning"
)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#---------------------------------------------------------------
# Configure source directory
#---------------------------------------------------------------
file(GLOB SRC_SOURCES src/*.cpp src/*/*.cpp)

#---------------------------------------------------------------
# Configure all sources
#---------------------------------------------------------------
set(SOURCES ${SRC_SOURCES} ${IMGUI_SOURCES} ${GLFW_DEPS_SOURCES})

#---------------------------------------------------------------
# Compiling and linking the project
#---------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME})

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
set(SOURCES ${SRC_SOURCES})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

#---------------------------------------------------------------
# Configure all includes
#---------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PUBLIC include)

#---------------------------------------------------------------
# Compiling and linking the project
#---------------------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

configure_file("./cmake/${PROJECT_NAME}.pc.in" "${PROJECT_NAME}.pc" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig")

cmake_minimum_required(VERSION 3.16)

# set the project name
project(tralc LANGUAGES C VERSION "0.2.0")

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# lib
#add_library(functionsLib src/functions.c src/morefunctions.c)

# add the executable
add_executable(tralc src/main.c)

configure_file(config.h.in config.h)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(tralc ${GTK3_LIBRARIES})


#target_link_libraries(myprogram functionsLib)

#target_include_directories(myprogram PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

#include_directories(${PROJECT_BINARY_BIN})
#target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

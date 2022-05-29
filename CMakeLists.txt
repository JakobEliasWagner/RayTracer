cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(
        sudoku
        VERSION 0.0
        DESCRIPTION "Sudoku solver and puzzle generator"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# define targets and sources
include(src/CMakeLists.txt)

# define standalone executables
include(standalone/CMakeLists.txt)


enable_testing()
add_subdirectory(test)